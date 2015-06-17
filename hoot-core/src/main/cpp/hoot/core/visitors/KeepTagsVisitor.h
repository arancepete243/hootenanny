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
#ifndef KEEPTAGSVISITOR_H
#define KEEPTAGSVISITOR_H

// hoot
#include <hoot/core/OsmMapConsumer.h>
#include <hoot/core/elements/Element.h>
#include <hoot/core/filters/ElementCriterion.h>
#include <hoot/core/util/Configurable.h>

#include "ElementOsmMapVisitor.h"

namespace hoot
{

/**
 * Keeps any tags with keys matching those passed to this visitor; removes all others
 */
class KeepTagsVisitor : public ElementOsmMapVisitor, public Configurable
{
public:

  static std::string className() { return "hoot::KeepTagsVisitor"; }

  KeepTagsVisitor();
  KeepTagsVisitor(QStringList keys);

  void setConfiguration(const Settings& conf);

  virtual void visit(const shared_ptr<Element>& e);

private:

  QStringList _keys;
};

}


#endif // KEEPTAGSVISITOR_H
