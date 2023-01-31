namespace sirius {
class NoneCopy {
public:
  NoneCopy() = default;

  ~NoneCopy() = default;

  NoneCopy(const NoneCopy&) = delete;

  NoneCopy& operator = (const NoneCopy&) = delete;
};
}