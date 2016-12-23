//
// ScriptContener.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec 21 18:14:04 2016 Gandoulf
// Last update Thu Dec 22 15:44:16 2016 Gandoulf
//

#ifndef MUTEXEDCONTENER_HPP_
# define MUTEXEDCONTENER_HPP_

# include <map>
# include "mutex"

namespace rtype
{
  template <class Contener>
  class MutexContener
  {
  public:
    MutexContener() {}
    ~MutexContener() {}

    void setContener(Contener const &contener)
    {
      _contenerMutex.lock();
      _contener = contener;
      _contenerMutex.unlock();
    }

    Contener &getContener()
    {
      _contenerMutex.lock();
      return (_contener);
    }

    void giveBackContener()
    {
      _contenerMutex.unlock();
    }

  private:
    Contener   _contener;
    std::mutex _contenerMutex;
  };
}

#endif /* MUTEXEDCONTENER_HPP_ */
