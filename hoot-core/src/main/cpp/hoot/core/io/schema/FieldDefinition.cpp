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
 * @copyright Copyright (C) 2013, 2014 DigitalGlobe (http://www.digitalglobe.com/)
 */
#include "FieldDefinition.h"

// hoot
#include <hoot/core/util/Log.h>

namespace hoot
{

FieldDefinition::FieldDefinition()
{
  _width = -1;
  _allowNull = true;
  _defaultIsNull = false;
}

void FieldDefinition::_reportError(const QString& field, const QString& error,
    StrictChecking strict) const
{
  if (strict == StrictOn)
  {
    throw InvalidValueException(field, error);
  }
  else if (strict == StrictWarn)
  {
    LOG_WARN("Error in field: " << field << " error: " << error);
  }
}

}
