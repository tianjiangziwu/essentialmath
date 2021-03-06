//===============================================================================
// @ IvVector4.h
// 
// 4D vector class
// ------------------------------------------------------------------------------
// Copyright (C) 2008-2015 by James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
//
//
//===============================================================================

#ifndef __IvVector4__h__
#define __IvVector4__h__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include "IvWriter.h"

//-------------------------------------------------------------------------------
//-- Typedefs, Structs ----------------------------------------------------------
//-------------------------------------------------------------------------------

class IvMatrix44;

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class IvVector4
{
    friend class IvMatrix44;
    
public:
    // constructor/destructor
    inline IvVector4() {}
    inline IvVector4( float _x, float _y, float _z, float _w ) :
        x(_x), y(_y), z(_z), w(_w)
    {
    }
    inline ~IvVector4() {}

    // copy operations
    IvVector4(const IvVector4& other);
    IvVector4& operator=(const IvVector4& other);

    // text output (for debugging)
    friend IvWriter& operator<<(IvWriter& out, const IvVector4& source);

    // accessors
    inline float& operator[]( unsigned int i )         { return (&x)[i]; }
    inline float operator[]( unsigned int i ) const    { return (&x)[i]; }

    float Length() const;
    float LengthSquared() const;

    // comparison
    bool operator==( const IvVector4& other ) const;
    bool operator!=( const IvVector4& other ) const;
    bool IsZero() const;
    bool IsUnit() const;

    // manipulators
    inline void Set( float _x, float _y, float _z, float _w );
    void Clean();       // sets near-zero elements to 0
    inline void Zero(); // sets all elements to 0
    void Normalize();   // sets to unit vector

    // operators

    // addition/subtraction
    IvVector4 operator+( const IvVector4& other ) const;
    IvVector4& operator+=( const IvVector4& other );
    IvVector4 operator-( const IvVector4& other ) const;
    IvVector4& operator-=( const IvVector4& other );

    // scalar multiplication
    IvVector4    operator*( float scalar );
    friend IvVector4    operator*( float scalar, const IvVector4& vector );
    IvVector4&          operator*=( float scalar );
    IvVector4    operator/( float scalar );
    IvVector4&          operator/=( float scalar );

    // dot product
    float              Dot( const IvVector4& vector ) const;
    friend float       Dot( const IvVector4& vector1, const IvVector4& vector2 );

    // matrix products
    friend IvVector4 operator*( const IvVector4& vector, const IvMatrix44& mat );

    // useful defaults
    static IvVector4    xAxis;
    static IvVector4    yAxis;
    static IvVector4    zAxis;
    static IvVector4    wAxis;
    static IvVector4    origin;
        
    // member variables
    float x, y, z, w;
};

//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ IvVector4::Set()
//-------------------------------------------------------------------------------
// Set vector elements
//-------------------------------------------------------------------------------
inline void 
IvVector4::Set( float _x, float _y, float _z, float _w )
{
    x = _x; y = _y; z = _z; w = _w;
}   // End of IvVector4::Set()

//-------------------------------------------------------------------------------
// @ IvVector4::Zero()
//-------------------------------------------------------------------------------
// Zero all elements
//-------------------------------------------------------------------------------
inline void 
IvVector4::Zero()
{
    x = y = z = w = 0.0f;
}   // End of IvVector4::Zero()

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------

#endif
