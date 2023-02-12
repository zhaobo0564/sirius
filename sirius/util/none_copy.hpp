//
// Created by zhaobo on 2023/1/10.
// email 1173007724@qq.com
//

#ifndef SIRIUS_NONE_COPY_HPP
#define SIRIUS_NONE_COPY_HPP
namespace sirius {
class NoneCopy {
public:
  NoneCopy() = default;

  ~NoneCopy() = default;

  NoneCopy(const NoneCopy&) = delete;

  NoneCopy& operator = (const NoneCopy&) = delete;
};
}
#endif