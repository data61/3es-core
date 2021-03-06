//
// author: Kazys Stepanas
//
#ifndef _3ESTEXT2D_H_
#define _3ESTEXT2D_H_

#include "3es-core.h"

#include "3esshape.h"

#include <cstdint>
#include <cstring>

namespace tes
{
/// A shape which renders screen space text, optionally positioned in 3D.
///
/// Positioning is in normalised screen coordinates.
/// Expects UTF-8 encoding.
class _3es_coreAPI Text2D : public Shape
{
public:
  // Text2D(const char *text, uint16_t textLength, const V3Arg &pos = V3Arg(0, 0, 0));
  Text2D(const char *text = "", const V3Arg &pos = V3Arg(0, 0, 0));
  // Text2D(const char *text, uint16_t textLength, uint32_t id, const V3Arg &pos = V3Arg(0, 0, 0));
  Text2D(const char *text, uint32_t id, const V3Arg &pos = V3Arg(0, 0, 0));
  // Text2D(const char *text, uint16_t textLength, uint32_t id, uint16_t category, const V3Arg &pos = V3Arg(0, 0, 0));
  /// Construct a box object.
  /// @param id The shape ID, unique among @c Arrow objects, or zero for a transient shape.
  /// @param category The category grouping for the shape used for filtering.
  Text2D(const char *text, uint32_t id, uint16_t category, const V3Arg &pos = V3Arg(0, 0, 0));
  /// Copy constructor
  Text2D(const Text2D &other);
  /// Move constructor
  Text2D(Text2D &&other);

  ~Text2D();

  inline const char *type() const override { return "text2D"; }

  bool inWorldSpace() const;
  Text2D &setInWorldSpace(bool worldSpace);

  inline char *text() const { return _text; }
  inline uint16_t textLength() const { return _textLength; }

  Text2D &setText(const char *text, uint16_t textLength);

  bool writeCreate(PacketWriter &stream) const override;

  bool readCreate(PacketReader &stream) override;

  Text2D &operator=(const Text2D &other);
  Text2D &operator=(Text2D &&other);

  Shape *clone() const override;

protected:
  void onClone(Text2D *copy) const;

private:
  char *_text;
  uint16_t _textLength;
};


// inline Text2D::Text2D(const char *text, uint16_t textLength, const V3Arg &pos)
//  : Shape(SIdText2D)
//  , _text(nullptr)
//  , _textLength(0)
//{
//  setPosition(pos);
//  setText(text, textLength);
//}


inline Text2D::Text2D(const char *text, const V3Arg &pos)
  : Shape(SIdText2D)
  , _text(nullptr)
  , _textLength(0)
{
  setPosition(pos);
  setText(text, text ? (uint16_t)strlen(text) : 0);
}


// inline Text2D::Text2D(const char *text, uint16_t textLength, uint32_t id, const V3Arg &pos)
//  : Shape(SIdText2D, id)
//  , _text(nullptr)
//  , _textLength(0)
//{
//  setPosition(pos);
//  setText(text, textLength);
//}


inline Text2D::Text2D(const char *text, uint32_t id, const V3Arg &pos)
  : Shape(SIdText2D, id)
  , _text(nullptr)
  , _textLength(0)
{
  setPosition(pos);
  setText(text, text ? (uint16_t)strlen(text) : 0);
}


// inline Text2D::Text2D(const char *text, uint16_t textLength, uint32_t id, uint16_t category, const V3Arg &pos)
//  : Shape(SIdText2D, id, category)
//  , _text(nullptr)
//  , _textLength(0)
//{
//  setPosition(pos);
//  setText(text, textLength);
//}


inline Text2D::Text2D(const char *text, uint32_t id, uint16_t category, const V3Arg &pos)
  : Shape(SIdText2D, id, category)
  , _text(nullptr)
  , _textLength(0)
{
  setPosition(pos);
  setText(text, text ? (uint16_t)strlen(text) : 0);
}


inline bool Text2D::inWorldSpace() const
{
  return (_data.flags & Text2DFWorldSpace) != 0;
}


inline Text2D &Text2D::setInWorldSpace(bool worldSpace)
{
  _data.flags = uint16_t(_data.flags & ~Text2DFWorldSpace);
  _data.flags = uint16_t(_data.flags | Text2DFWorldSpace * !!worldSpace);
  return *this;
}
}  // namespace tes

#endif  // _3ESTEXT2D_H_
