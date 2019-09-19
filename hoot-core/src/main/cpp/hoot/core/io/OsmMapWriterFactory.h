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
 * @copyright Copyright (C) 2015, 2016, 2017, 2018, 2019 DigitalGlobe (http://www.digitalglobe.com/)
 */
#ifndef OSMMAPWRITERFACTORY_H
#define OSMMAPWRITERFACTORY_H

// Hoot
//#include <hoot/core/elements/OsmMap.h>
#include <hoot/core/conflate/network/NetworkMatcher.h>
#include <hoot/core/io/ElementInputStream.h>

// Qt
#include <QString>

// Standard
#include <memory>

namespace hoot
{

class OsmMapWriter;
class OsmMap;

/**
 * A factory for constructing writers based on the URL
 */
class OsmMapWriterFactory
{
public:

  static std::shared_ptr<OsmMapWriter> createWriter(const QString& url);

  static bool hasElementOutputStream(const QString& url);

  static void write(const std::shared_ptr<OsmMap>& map, const QString& url,
                    const bool silent = false, const bool is_debug = false);

  static QString getWriterName(const QString& url);

  static bool isSupportedFormat(const QString& url);

  static void writeDebugMap(const std::shared_ptr<const OsmMap>& map, const QString& title = "",
                            NetworkMatcherPtr matcher = NetworkMatcherPtr());

private:

  static unsigned int _debugMapCount;
};

}

#endif // OSMMAPWRITERFACTORY_H
