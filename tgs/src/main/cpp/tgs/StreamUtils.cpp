/*
 * This file is part of Hootenanny.
 *
 * Hootenanny is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * The following copyright notices are generated automatically. If you
 * have a new notice to add, please use the format:
 * " * @copyright Copyright ..."
 * This will properly maintain the copyright information. DigitalGlobe
 * copyrights will be updated automatically.
 *
 * @copyright Copyright (C) 2013 DigitalGlobe (http://www.digitalglobe.com/)
 */

#include "StreamUtils.h"

#if HAVE_LIBNEWMAT
// Newmat Includes
#undef use_namespace
#include <newmat/newmat.h>
using namespace NEWMAT;

namespace Tgs
{
  std::ostream& operator<<(std::ostream & o, const Matrix& matrix)
  {
    o << "[";
    for (int r = 0; r < matrix.Nrows(); r++)
    {
      if (r != 0)
      {
        o << " ";
      }
      o << "[";
      for (int c = 0; c < matrix.Ncols(); c++)
      {
        if (c != 0)
        {
          o << ", ";
        }
        o << matrix.element(r, c);
      }
      o << "]";
      if (r != matrix.Nrows() - 1)
      {
        o << endl;
      }
    }
    o << "]" << endl;
    return o;
  }
}
#endif

