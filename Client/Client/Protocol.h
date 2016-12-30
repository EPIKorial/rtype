/*
** Protocol.h for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Protocol
**
** Made by Gandoulf
** Login   <gandoulf@epitech.net>
**
** Started on  Wed Dec  7 15:17:18 2016 Gandoulf
** Last update Fri Dec 16 10:20:19 2016 Gandoulf
*/

#ifndef PROTOCOL_H_
# define PROTOCOL_H_

# define MAGIC_NUMBER 79
# define MAX_PAQUET_SIZE 1000

#ifdef _WIN32
#define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop) )
#else
#define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#endif

extern "C"
{
  typedef enum		EventType
    {
      MESSAGE,
      POSUPDATE,
      FIRE,
      INSTANTIATE,
      COLLISION,
      DELETION
    }			EventType;

  PACK (
  typedef struct	Header
  {
    unsigned char	magicNumber;
    unsigned short	size;
    unsigned char	checksum;
    unsigned char	messageType;
  })			Header;

  PACK (
  typedef struct	PosUpdate
  {
    unsigned int	ID;
    float		x;
    float		y;
  })			PosUpdate;

  PACK (
  typedef struct	Fire
  {
    unsigned int	ID;
    float		x;
    float		y;
    unsigned short	bulletID;
  })			Fire;

  PACK (
  typedef struct	Instantiate
  {
    unsigned int	ID;
    float		x;
    float		y;
    float		scale_x;
    float		scale_y;
    unsigned short	goID;
  })			Instantiate;

  PACK (
  typedef struct	Collision
  {
    unsigned int	ID1;
    unsigned int	ID2;
  })			Collision;

  PACK (
  typedef struct	Deletion
  {
    unsigned int	ID;
  })			Deletion;
}

#endif /* PROTOCOL_H_ */
