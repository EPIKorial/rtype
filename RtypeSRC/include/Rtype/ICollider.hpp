#ifndef ICOLLIDER_HPP_
# define ICOLLIDER_HPP_

namespace rtype
{
  class ICollider
  {
  public:
    ICollider() {}
    virtual ~ICollider() {}
    
    virtual bool checkCollision(ICollider const& other) = 0;
  };
};

#endif // ICOLLIDER_HPP_
