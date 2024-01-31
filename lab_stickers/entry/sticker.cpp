#include "Image.h"
#include "StickerSheet.h"

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image make_picture; make_picture.readFromFile("../data/alma.png");
  Image image1;    image1.readFromFile("../data/i.png");
  Image image2;    image2.readFromFile("../data/penguin.png");
  Image image3;    image3.readFromFile("../data/i.png");
  StickerSheet sheet(make_picture, 3);
  sheet.addSticker(image1, 300, 200);
  sheet.addSticker(image2, 50, 500);
  sheet.addSticker(image3, 800, 100);
  Image rendered = sheet.render();
  rendered.writeToFile("../data/myImage.png");

  return 0;
}
