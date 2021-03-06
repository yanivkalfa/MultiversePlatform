/*
============================================================================
This source file is part of the Ogre-Maya Tools.
Distributed as part of Ogre (Object-oriented Graphics Rendering Engine).
Copyright (C) 2003 Fifty1 Software Inc., Bytelords

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
or go to http://www.gnu.org/licenses/gpl.txt
============================================================================
*/
#ifndef _OGREMAYA_COMMON_H_
#define _OGREMAYA_COMMON_H_

#if defined( _MSC_VER )
// Turn off warnings generated by long std templates
// This warns about truncation to 255 characters in debug/browse info
#   pragma warning (disable : 4786)
#endif

namespace OgreMaya { 

    typedef float Real;

    template <typename Iterator>
    void deleteAll(Iterator it, Iterator end) {                
        for(;it!=end; ++it)
            delete *it;
    }

    template <typename Iterator>
    bool listEqual(Iterator it1, Iterator it2, Iterator end1, Iterator end2) {        
        bool eq = true;
        while(eq && it1!=end1 && it2!=end2) {
            eq = *it1 == *it2;
            ++it1;
            ++it2;
        }        

        return 
            eq && it1==end1 && it2==end2;
    }


    struct Vector3 {
        Real x,y,z;

        Vector3(): x(0), y(0), z(0) {}

        bool operator ==(const Vector3& other) const {
            return x==other.x && y==other.y && z==other.z;
        }
		Vector3 &operator *=(float mult) {
			x = (Real)mult * x;
			y = (Real)mult * y;
			z = (Real)mult * z;
			return *this;
		}
    };

    struct ColourValue {
        Real r,g,b,a;

        ColourValue(): r(0), g(0), b(0), a(1) {}

        bool operator ==(const ColourValue& other) const {
            return r==other.r && g==other.g && b==other.b && a==other.a;
        }
    };

}

#endif
