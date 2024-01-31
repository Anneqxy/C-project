#include <cmath>
#include <iterator>
#include <iostream>

#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "Point.h"

#include "ImageTraversal.h"

namespace Traversals {
  /**
  * Calculates a metric for the difference between two pixels, used to
  * calculate if a pixel is within a tolerance.
  *
  * @param p1 First pixel
  * @param p2 Second pixel
  * @return the difference between two HSLAPixels
  */
  double calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
    double h = fabs(p1.h - p2.h);
    double s = p1.s - p2.s;
    double l = p1.l - p2.l;

    // Handle the case where we found the bigger angle between two hues:
    if (h > 180) { h = 360 - h; }
    h /= 360;

    return sqrt((h*h) + (s*s) + (l*l));
  }
  
  /**
  * Adds a Point for the bfs traversal to visit at some point in the future.
  * @param work_list the deque storing a list of points to be processed
  * @param point the point to be added
  */
  void bfs_add(std::deque<Point> & work_list, const Point & point) {
    /** @todo [Part 1] */
    work_list.push_back(point);
  }

  /**
  * Adds a Point for the dfs traversal to visit at some point in the future.
  * @param work_list the deque storing a list of points to be processed
  * @param point the point to be added
  */
  void dfs_add(std::deque<Point> & work_list, const Point & point) {
    /** @todo [Part 1] */
    work_list.push_front(point);
  }

  /**
  * Removes the current Point in the bfs traversal
  * @param work_list the deque storing a list of points to be processed
  */
  void bfs_pop(std::deque<Point> & work_list) {
    /** @todo [Part 1] */
    work_list.pop_front();
  }

  /**
  * Removes the current Point in the dfs traversal
  * @param work_list the deque storing a list of points to be processed
  */
  void dfs_pop(std::deque<Point> & work_list) {
    /** @todo [Part 1] */
    work_list.pop_front();
  }

  /**
   * Returns the current Point in the bfs traversal
   * @param work_list the deque storing a list of points to be processed
   * @return the current Point 
   */
  Point bfs_peek(std::deque<Point> & work_list) {
    /** @todo [Part 1] */
    return work_list.front();
  }

  /**
   * Returns the current Point in the dfs traversal
   * @param work_list the deque storing a list of points to be processed
   * @return the current Point 
   */
  Point dfs_peek(std::deque<Point> & work_list) {
    /** @todo [Part 1] */
    return work_list.front();
  }

  /**
  * Initializes a ImageTraversal on a given `png` image,
  * starting at `start`, and with a given `tolerance`.
  * @param png The image this traversal is going to traverse
  * @param start The start point of this traversal
  * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
  * it will not be included in this traversal
  * @param fns the set of functions describing a traversal's operation
  */
  ImageTraversal::ImageTraversal(const PNG & png, const Point & start, double tolerance, TraversalFunctions fns) {  
    /** @todo [Part 1] */
    png_ = &png;
    start_ = start;
    tolerance_ = tolerance;
    fns_ = fns;
  }

  /**
  * Returns an iterator for the traversal starting at the first point.
  */
  ImageTraversal::Iterator ImageTraversal::begin() {
    /** @todo [Part 1] */
    return Iterator(this, start_);
  }

  /**
  * Returns an iterator for the traversal one past the end of the traversal.
  */
  ImageTraversal::Iterator ImageTraversal::end() {
    /** @todo [Part 1] */
    return Iterator();
  }

  /**
  * Default iterator constructor.
  */
  ImageTraversal::Iterator::Iterator() {
    /** @todo [Part 1] */
    // current_ = Point(0, 0);
    // calculate = 0;
    traversal_ = nullptr;
  }

  ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, const Point & start) {
    traversal_ = traversal;
    // calculate = traversal_->tolerance_;
    current_ = traversal_->start_;
    traversal_->fns_.add(work_list_, traversal_->start_);
    // std::cout << current_ << std::endl;
    visited_.resize(traversal_->png_->width());
    for(std::vector<bool>& v: visited_) {
      v.resize(traversal_->png_->height());
    }
    for (unsigned int w = 0; w < traversal_->png_->width(); w++){
      for (unsigned int h = 0; h < traversal_->png_->height(); h++){
        visited_[w][h]=true;
      }
    }
  }




  /**
  * Iterator increment operator.
  *
  * Advances the traversal of the image.
  */
  ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
    /** @todo [Part 1] */
    Point current = traversal_->fns_.peek(work_list_);
    traversal_->fns_.pop(work_list_);

    visited_[current.x][current.y] = false;

    unsigned int x = current.x;
    unsigned int y = current.y;

    Point left = Point(x - 1, y);
    Point up = Point(x, y - 1);

    if (x + 1 < traversal_->png_->width()) {
      Point right(x + 1, y);
      if (calculateDelta(traversal_->png_->getPixel(traversal_->start_.x, traversal_->start_.y), traversal_->png_->getPixel(right.x, right.y)) < traversal_->tolerance_) {
        traversal_->fns_.add(work_list_, right);
      }
    }

    if (y + 1 < traversal_->png_->height()) {
      Point below(x, y + 1);
      if (calculateDelta(traversal_->png_->getPixel(traversal_->start_.x, traversal_->start_.y), traversal_->png_->getPixel(below.x, below.y)) < traversal_->tolerance_) {
        traversal_->fns_.add(work_list_, below);
      }
    }

    if (isVistable(left)) {
      // Point left(x - 1, y);
      // if (calculateDelta(traversal_->png_->getPixel(traversal_->start_.x, traversal_->start_.y), traversal_->png_->getPixel(left.x, left.y)) < traversal_->tolerance_) {
      //   traversal_->fns_.add(work_list_, left);
      // }
      traversal_->fns_.add(work_list_, left);
    }

    if (isVistable(up)) {
      // Point above(x, y - 1);
      // if (calculateDelta(traversal_->png_->getPixel(traversal_->start_.x, traversal_->start_.y), traversal_->png_->getPixel(above.x, above.y)) < traversal_->tolerance_) {
      //   traversal_->fns_.add(work_list_, above);
      // }
      traversal_->fns_.add(work_list_, up);
    }

    while (!work_list_.empty() && !(visited_[work_list_.front().x][work_list_.front().y])) {
      traversal_->fns_.pop(work_list_);
    }
    if (!work_list_.empty()) {
      current_ = traversal_->fns_.peek(work_list_);
    } else {
      traversal_ = nullptr;
    }
    return *this;
  }

bool ImageTraversal::Iterator::isVistable(Point curr) {
  if(curr.x >= traversal_->png_->width() || curr.y >= traversal_->png_->height()) {
    return false;
  }
  if(0 > curr.x || 0 > curr.y) {
    return false;
  }
  auto temp1 = traversal_->png_->getPixel(traversal_->start_.x, traversal_->start_.y);
  auto temp2 = traversal_->png_->getPixel(curr.x, curr.y);
  if(calculateDelta(temp1, temp2) >= traversal_->tolerance_) {
    return false;
  }
  return true;
}





  /**
  * Iterator accessor operator.
  *
  * Accesses the current Point in the ImageTraversal.
  */
  Point ImageTraversal::Iterator::operator*() {
    /** @todo [Part 1] */
    return current_;
  }

  /**
  * Iterator inequality operator.
  *
  * Determines if two iterators are not equal.
  */
  bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
    /** @todo [Part 1] */
    if (work_list_.empty()) {};
    return !work_list_.empty();
    // return !(work_list_.empty() && other.work_list_.empty());
  }

  /**
   * Iterator size function.
   *
   * @return size_t the size of the iterator work queue.
   */
  size_t ImageTraversal::Iterator::size() const {
    return work_list_.size();
  }

  /**
   * Iterator empty function.
   *
   * @return bool whether the iterator work queue is empty.
   */
  bool ImageTraversal::Iterator::empty() const {
    return work_list_.empty();
  }

}