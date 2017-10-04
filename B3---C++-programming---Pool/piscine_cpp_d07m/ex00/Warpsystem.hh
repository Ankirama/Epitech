#ifndef WARPSYSTEM_HH_
# define WARPSYSTEM_HH_

namespace WarpSystem {
  class QuantumReactor {
  public:
    QuantumReactor();
    ~QuantumReactor();
    bool isStable();
    void setStability(bool stability);

  private: /* data */
    bool _stability;
  };

  class Core {
  public:
    Core(QuantumReactor *reactor);
    ~Core();
    QuantumReactor *checkReactor();

  private: /* data */
    QuantumReactor *_coreReactor;
  };
}

#endif /* !WARPSYSTEM_HH_ */
