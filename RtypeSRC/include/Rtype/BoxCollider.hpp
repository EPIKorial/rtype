#ifndef BOXCOLLIDER_HPP_
# define BOXCOLLIDER_HPP_

# include "ICollider.hpp"

namespace rtype
{
  class BoxCollider : public ICollider
  {
  public:
    BoxCollider();
    virtual ~BoxCollider();
    
    /**
     * Struct representing the box collider.
     * X and Y must be the top left corner of the collider.
     * W and H are respectively the Width and Height of the collider.
     */
    typedef struct AABB
    {
      float x;
      float y;
      float w;
      float h;
    } AABB;
    
    virtual bool checkCollision(ICollider const& other);

    bool checkBoxCollision(BoxCollider const& other);
    
    AABB box;
  };
};

#endif // BOXCOLLIDER_HPP_
