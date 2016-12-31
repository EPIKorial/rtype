#include "BoxCollider.hpp"

namespace rtype
{
  BoxCollider::BoxCollider()
  {

  }

  BoxCollider::~BoxCollider()
  {

  }

  /**
   * Only works for collisions between rtype::BoxCollider for now
   */
  bool BoxCollider::checkCollision(ICollider const& other)
  {
    bool result;

    try 
      {
	result = checkBoxCollision(dynamic_cast<BoxCollider const&>other);
      }
    catch (const std::exception& e)
      {
	std::cerr << e.what() << std::endl;
	result = false;
      }

    return result;
  }

  bool BoxCollider::checkBoxCollision(BoxCollider const& other)
  {
    return ((other.box.x >= box.x + box.w)
	    || (other.box.x + other.box.w <= box.x)
	    || (other.box.y >= box.y + box.h)
	    || (other.box.y + other.box.h <= box.y));
  }
};
