#include "Image.h"
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
using namespace cs225;

Image::Image () {
    PNG();
}

Image::Image (unsigned int width, unsigned int height) {
    PNG(width, height);
}

void Image::lighten() {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double light = pixel.l;
            light = light + 0.1;
            if (light < 0.0) {
                light = 0.0;
            } else if (light > 1.0) {
                light = 1.0;
            }
            pixel.l = light;
        }
    }
}

void Image::lighten (double amount) {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double light = pixel.l;
            light = light + amount;
            if (light < 0.0) {
                light = 0.0;
            } else if (light > 1.0) {
                light = 1.0;
            }
            pixel.l = light;
        }
    }
}

void Image::darken () {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double luminance = pixel.l;
            luminance = luminance - 0.1;
            if (luminance < 0.0) {
                luminance = 0.0;
            } else if (luminance > 1.0) {
                luminance = 1.0;
            }
            pixel.l = luminance;
        }
    }
}

void Image::darken (double amount) {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double luminance = pixel.l;
            luminance = luminance - amount;
            if (luminance < 0.0) {
                luminance = 0.0;
            } else if (luminance > 1.0) {
                luminance = 1.0;
            }
            pixel.l = luminance;
        }
    }
}

void Image::saturate () {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double saturate = pixel.s;
            saturate = saturate + 0.1;
            if (saturate < 0.0) {
                saturate = 0.0;
            } else if (saturate > 1.0) {
                saturate = 1.0;
            }
            pixel.s = saturate;
        }
    }
}

void Image::saturate (double amount) {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double saturate = pixel.s;
            saturate = saturate + amount;
            if (saturate < 0.0) {
                saturate = 0.0;
            } else if (saturate > 1.0) {
                saturate = 1.0;
            }
            pixel.s = saturate;
        }
    }
}

void Image::desaturate () {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double saturate = pixel.s;
            saturate = saturate - 0.1;
            if (saturate < 0.0) {
                saturate = 0.0;
            } else if (saturate > 1.0) {
                saturate = 1.0;
            }
            pixel.s = saturate;
        }
    }
}

void Image::desaturate (double amount) {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double saturate = pixel.s;
            saturate = saturate - amount;
            if (saturate < 0.0) {
                saturate = 0.0;
            } else if (saturate > 1.0) {
                saturate = 1.0;
            }
            pixel.s = saturate;
        }
    }
}

void Image::grayscale () {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            pixel.s = 0;
        }
    }
}
void Image::rotateColor (double degrees) {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double hue = pixel.h;
            hue = hue + degrees;
            if (hue > 360.0) {
                hue = hue - 360;
            } else if (hue < 0.0) {
                hue = hue + 360.0;
            }
            pixel.h = hue;
        }
    }
}

void Image::illinify () {
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& pixel = getPixel(x, y);
            double hue = pixel.h;
            double distant_orange = std::min(std::abs(hue-11), 360-std::abs(hue-11));
            double distant_blue = std::min(std::abs(hue-216), 360-std::abs(hue-216));
            if (distant_orange < distant_blue) {
                pixel.h = 11;
            } else {
                pixel.h = 216;
            }
        }
    }
}

void Image::scale (double factor) {
    if (factor == 1.0) {
        return;
    }
    PNG to_store = *this;
    unsigned int newWidth = static_cast<unsigned>(this->width() * factor);
    unsigned int newHeight = static_cast<unsigned>(this->height() * factor);
    resize(newWidth, newHeight);
    for (unsigned int y = 0; y < height(); y++) {
        for (unsigned int x = 0; x < width(); x++) {
            HSLAPixel& newpixel = getPixel(x, y);
            newpixel = to_store.getPixel(x/factor, y/factor);
        }
    }
}

void Image::scale (unsigned w, unsigned h) {
    double widthFactor = static_cast<double>(w) / static_cast<double>(this->width());
    double heightFactor = static_cast<double>(h) / static_cast<double>(this->height());
    double factor = std::min(widthFactor, heightFactor);
    //unsigned int newWidth = static_cast<unsigned>(this->width() * factor);
    //unsigned int newHeight = static_cast<unsigned>(this->height() * factor);
    //resize(newWidth, newHeight);
    scale(factor);
}