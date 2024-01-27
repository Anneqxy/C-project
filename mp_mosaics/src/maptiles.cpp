/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>

#include "maptiles.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
    MosaicCanvas* to_return = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    vector<Point<3>> convert;
    std::map<Point<3>, TileImage*> map;
    for (TileImage& i : theTiles) {
        LUVAPixel pixel = i.getAverageColor();
        convert.push_back(convertToXYZ(pixel));
        map[convertToXYZ(pixel)] = &i;
    }
    KDTree<3> Tree(convert);
    for (int i = 0; i < theSource.getRows(); i++) {
        for (int j = 0; j < theSource.getColumns(); j++) {
            Point<3> pixel = convertToXYZ(theSource.getRegionColor(i, j));
            Point<3> to_find = Tree.findNearestNeighbor(pixel);
            to_return->setTile(i, j, map[to_find]);
        }
    }
    return to_return;
}

