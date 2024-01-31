z#include "Image.h"
#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace cs225;



StickerSheet::StickerSheet (const Image &picture, unsigned max) {
    basePicture_ = picture;
    maxStickers_ = max;
    stickers_.resize(max, nullptr); 
    x_coor.resize(max, 0);
    y_coor.resize(max, 0);
}

StickerSheet::StickerSheet (const StickerSheet &other) {
    _copy(other);
}

int StickerSheet::addSticker (Image &sticker, int x, int y) {
    bool flag = false;
    unsigned int i = 0;
    while (i < stickers_.size() && flag == false) {
        if (stickers_[i] == nullptr) {
            stickers_[i] = &sticker;
            x_coor[i] = x;
            y_coor[i] = y;
            flag = true;
        }
        i++;
    }
    if (flag == false) {
        maxStickers_++;
        stickers_.push_back(&sticker);
        x_coor.push_back(x);
        y_coor.push_back(y);
    } else {
        i--;
    }
    return i;
}

void StickerSheet::_copy(const StickerSheet &other) {
//     basePicture_ = other.basePicture_;
//     maxStickers_ = other.maxStickers_;
//     stickers_.resize(other.stickers_.size());
//     x_coor.resize(other.stickers_.size());
//     y_coor.resize(other.stickers_.size());
//     for (size_t i = 0; i < other.stickers_.size(); ++i) {
//         if (other.stickers_[i] != nullptr) {
//             stickers_[i] = new Image(*(other.stickers_[i])); // 为什么这要dereference
//             x_coor[i] = other.x_coor[i];
//             y_coor[i] = other.y_coor[i];
//         } else {
//             stickers_[i] = nullptr;
//             x_coor[i] = 0;
//             y_coor[i] = 0;
//         }
//     }

    // if (this == &other) {
    //     return *this;
    // }
    basePicture_ = other.basePicture_;
    maxStickers_ = other.maxStickers_;
    stickers_.assign(other.stickers_.begin(), other.stickers_.end());
    x_coor.assign(other.x_coor.begin(), other.x_coor.end());
    y_coor.assign(other.y_coor.begin(), other.y_coor.end());
    // return *this;
}




const StickerSheet& StickerSheet::operator= (const StickerSheet &other) {
    if (this != &other) {
        _copy(other);
    }
    return *this;

    // if (this == &other) {
    //     return *this;
    // }
    // basePicture_ = other.basePicture_;
    // maxStickers_ = other.maxStickers_;
    // stickers_.aasign(other.stickers_.begin(), other.stickers_.end());
    // x_coor.assign(other.x_coor.begin(), other.x_coor.end());
    // y_coor.aasign(other.y_coor.begin(), other.y_coor.end());
    // return *this;
}



void StickerSheet::changeMaxStickers (unsigned max) {
    if(max < maxStickers_) {
        stickers_.resize(max);
        x_coor.resize(max);
        y_coor.resize(max);
    } else {
        stickers_.resize(max, nullptr);
        x_coor.resize(max, 0);
        y_coor.resize(max, 0);
    }
    maxStickers_ = max;
}

int StickerSheet::setStickerAtLayer (Image &sticker, unsigned layer, int x, int y) {
    if (layer >= stickers_.size() || layer < 0) {
        return -1;
    }
    stickers_[layer] = new Image(sticker); //这块不需要dereference
    x_coor[layer] = x;
    y_coor[layer] = y;
    return layer;
}


bool StickerSheet::translate (unsigned index, int x, int y) {
    if (index < stickers_.size() && stickers_[index] != nullptr) {
        x_coor[index] = x;
        y_coor[index] = y;
        return true;
    }
    return false;
}

void StickerSheet::removeSticker (unsigned index) {
    if (index >= stickers_.size()) {
        return; 
    }
    if (stickers_[index] != nullptr) {
        stickers_[index] = nullptr;  
    }
    x_coor[index] = 0;
    y_coor[index] = 0;
}

Image* StickerSheet::getSticker (unsigned index) {
    if (index < stickers_.size() && stickers_[index] != nullptr && index >= 0) {
        return stickers_[index];
    }
    return NULL;
}

int StickerSheet::layers () const {
    return stickers_.size();
}

Image StickerSheet::render () const {
    unsigned int x_left = 0;
    unsigned int y_up = 0;
    unsigned int x_right = 0;
    unsigned int y_down = 0;
    for (unsigned int i = 0; i < stickers_.size(); ++i) {
        if (stickers_[i] != nullptr) {
            unsigned int potential_width = 0;
            unsigned int potential_height = 0;
            unsigned int x_left_change = 0;
            unsigned int y_up_change = 0;
            unsigned int x_right_change = 0;
            unsigned int y_down_change = 0;
            if (x_coor[i] < 0 && y_coor[i] < 0) {
                x_left_change = abs(x_coor[i]);
                y_up_change = abs(y_coor[i]);
            } else if (x_coor[i] < 0 && y_coor[i] > 0) {
                potential_height = static_cast<unsigned int>(y_coor[i] + stickers_[i]->height());
                x_left_change = abs(x_coor[i]);
                if (potential_height > basePicture_.height()) {
                    y_down_change = potential_height - basePicture_.height();
                }
            } else if (y_coor[i] < 0 && x_coor[i] > 0) {
                potential_width = static_cast<unsigned int>(x_coor[i] + stickers_[i]->width());
                y_up_change = abs(y_coor[i]);
                if (potential_width > basePicture_.width()) {
                    x_right_change = potential_width - basePicture_.width();
                }
            } else {
                potential_width = static_cast<unsigned int>(x_coor[i] + stickers_[i]->width());
                potential_height = static_cast<unsigned int>(y_coor[i] + stickers_[i]->height());
                if (potential_width > basePicture_.width()) {
                    x_right_change = potential_width - basePicture_.width();
                } else if (potential_height > basePicture_.height()) {
                    y_down_change = potential_height - basePicture_.height();
                }
            }

            if (x_left_change > x_left) {
                x_left = x_left_change;
            }
            if (y_up_change > y_up) {
                y_up = y_up_change;
            }
            if (y_down_change > y_down) {
                y_down = y_down_change;
            }
            if ( x_right_change >  x_right) {
                x_right =  x_right_change;
            }
        }
    }
    unsigned int new_width = basePicture_.width() + x_left + x_right;
    unsigned int new_height = basePicture_.height() + y_down + y_up;

    Image newpicture;
    newpicture.resize(new_width, new_height);
    
    for (unsigned int x = 0; x < basePicture_.width(); ++x) {
        for (unsigned int y = 0; y < basePicture_.height(); ++y) {
            newpicture.getPixel(x+x_left, y+y_up) = basePicture_.getPixel(x, y);
        }
    }

    for (unsigned int i = 0; i < stickers_.size(); ++i) {
        if (stickers_[i] != nullptr) {
            for (unsigned int x = 0; x < stickers_[i]->width(); ++x) {
                for (unsigned int y = 0; y < stickers_[i]->height(); ++y) {
                    HSLAPixel & sticker_pixel = stickers_[i]->getPixel(x, y);
                    if (sticker_pixel.a != 0) {
                        newpicture.getPixel(x_coor[i] + x + x_left, y_coor[i] + y + y_up) = sticker_pixel;
                    }
                }
            }
        }
    }
    return newpicture;
}

