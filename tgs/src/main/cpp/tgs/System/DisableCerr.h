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
 * @copyright Copyright (C) 2015 DigitalGlobe (http://www.digitalglobe.com/)
 */

#ifndef DISABLECERR_H
#define DISABLECERR_H

// Standard
#include <ostream>

namespace Tgs
{

/**
 * Temporarily disable cerr by redirecting to an empty ostream. When destructed cerr is
 * re-established. This is mostly useful when instantiating poorly behaved libraries (e.g. Octave)
 */
class DisableCerr
{
public:
  DisableCerr();

  ~DisableCerr();

private:
  std::ostream _nullStream;
  std::streambuf* _oldBuf;
};

}

#endif // DISABLECERR_H
