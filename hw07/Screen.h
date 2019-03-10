#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <opencv2/opencv.hpp>

/**
 * @brief Singleton screen class used for show graph.
 */
class Screen{
 public:
  int getWidth() const;

  int getHeight() const;

  /**
   * @brief Get singleton instance. Must to be static method since the
   * singleton instance may not has been created.
   */
  static Screen* getInstance(int width = 640, int height = 480);

  static void deleteInstance();

  void showGraph(const cv::Mat& graph) const;

 private:
  /**
   * @brief  Private constructor, so the singleton instance can only be
   * created by getInstance().
   * @see getInstance()
   */
  Screen();

  Screen(const Screen&);
  ~Screen();

  // Static attributes to be set by getInstance()
  static int width_;
  static int height_;
  static Screen* instance_;

  std::string name_ = "screen";
  std::string enter_;
  std::string leave_;
};

#endif