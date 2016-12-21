//
// PrefabCreator.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include/IndieStudio
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed May 25 14:52:42 2016 Gandoulf
// Last update Tue Dec 20 12:24:48 2016 Gandoulf
//

#ifndef PREFABCREATOR_HPP_
# define PREFABCREATOR_HPP_

# include "Rtype/Properties.hpp"
# include "Rtype/IndieParser.hpp"
# include "Rtype/LibraryLoader.hpp"
# include <map>

typedef rtype::AScript *(*skillScript)(rtype::GameObject *);

namespace rtype
{
  class PrefabLoadFileError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "Error while loading prefabFile, can't instanciate any object";
    }
  };

  class PrefabRenderObjectTypeError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "Error wrong RenderObjectType";
    }
  };

  class PrefabLibraryLoaderError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "Error while loading library";
    }
  };

  struct Prefab
  {
    Prefab()
      : _usable(true)
    {}
    bool                        _usable;
    Properties                  _properties;
  };

  class PrefabCreator
  {
  public:
    PrefabCreator();
    ~PrefabCreator();

    GameObject	*instantiate(std::string const &prefabFile,
			     Vector2F const & position,
			     Vector2F const & scale = Vector2F(1, 1));

  private:
    void loadFile(std::string const &prefabFile);

    void getName(Properties & _properties);
    void getTag(Properties & _properties);
    void getScript(Properties & _properties);
    void loadLibrary(Properties & _properties, Memory::LibraryLoader & _library,
		     bool & _usable, int it);
    //void getCollider(Properties & _properties);
    void getPosition(Properties & _properties);
    void getScale(Properties & _properties);

    //instantiate private methode

    void instantiateRenderObject(Properties & _properties,
				 GameObject *&gameObject,
				 Vector2F const & position,
				 Vector2F const & scale);
    void instantiateMeshObject(Properties & _properties,
			       GameObject *&gameObject,
			       Vector2F const & position,
			       Vector2F const & scale);

    std::string randomiseName(std::string &name);

  private:
    std::map<std::string, Prefab>			_prefab;
    std::map<std::string, Memory::LibraryLoader>	_lib;
    IndieParser						_parser;
  };
};

#endif /* PREFABCREATOR_HPP_ */
