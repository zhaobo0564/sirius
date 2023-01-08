#include "../../sirius/util/lock/spin_lock.hpp"

int main() {
  Spinlock spin_lock;
  spin_lock.lock();
  return 0;
}