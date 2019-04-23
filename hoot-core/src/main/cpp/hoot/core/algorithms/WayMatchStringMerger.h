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
 * @copyright Copyright (C) 2016, 2017, 2018, 2019 DigitalGlobe (http://www.digitalglobe.com/)
 */
#ifndef WAYSTRINGMERGER_H
#define WAYSTRINGMERGER_H

// hoot
#include <hoot/core/algorithms/linearreference/WaySublineMatchString.h>
#include <hoot/core/algorithms/linearreference/WayMatchStringMapping.h>
#include <hoot/core/schema/TagMerger.h>

namespace hoot
{

class WayMatchStringMergerTest;

/**
 * Provides methods for merging features/geometries in one string of ways into another string of
 * ways.
 */
class WayMatchStringMerger
{

public:

  static std::string className() { return "hoot::WayMatchStringMerger"; }

  static int logWarnCount;

  class SublineMapping
  {
  public:

    WayLocation getEnd1() const { return _end; }
    WayLocation getEnd2() const { return _subline2.getEnd(); }
    WayLocation getEnd(WayNumber way) { return (way == WayNumber::Way1) ? getEnd1() : getEnd2(); }

    WayPtr getNewWay1() const { return _newWay1; }
    WayPtr getNewWay2() const { return _newWay2; }
    WayPtr getNewWay(WayNumber way)
    { return (way == WayNumber::Way1) ? getNewWay1() : getNewWay2(); }

    WayLocation getStart1() const { return _start; }
    WayLocation getStart2() const { return _subline2.getStart(); }
    WayLocation getStart(WayNumber way) const
    { return (way == WayNumber::Way1) ? getStart1() : getStart2(); }
    /**
     * This is only valid if start and end are part of the same way which is not guaranteed.
     */
    WaySubline getSubline1() const { return WaySubline(_start, _end); }

    void setWay2(ConstWayPtr way2) { _way2 = way2; }

    void setNewWay1(WayPtr newWay1) { _newWay1 = newWay1; }
    void setNewWay2(WayPtr newWay2) { _newWay2 = newWay2; }
    void setNewWay(WayNumber way, WayPtr newWay)
    { (way == WayNumber::Way1) ? setNewWay1(newWay) : setNewWay2(newWay); }

    void setStart1(WayLocation start) { _start = start; }
    void setEnd1(WayLocation end) { _end = end; }

    void setSubline2(const WaySubline& ws) { _subline2 = ws; }

    QString toString() const;

  private:

    WaySubline _subline2;
    ConstWayPtr _way2;
    WayLocation _start;
    WayLocation _end;
    WayPtr _newWay1;
    WayPtr _newWay2;
  };
  typedef boost::shared_ptr<SublineMapping> SublineMappingPtr;

  class SublineMappingLessThan
  {
  public:

    SublineMappingLessThan(WayNumber way) { _way = way; }

    inline bool operator()(const WayMatchStringMerger::SublineMappingPtr &t1,
                           const WayMatchStringMerger::SublineMappingPtr &t2) const
    {
        return
          std::min(t1->getStart(_way), t1->getEnd(_way)) <
          std::min(t2->getStart(_way), t2->getEnd(_way));
    }

  private:

    WayNumber _way;
  };

  WayMatchStringMerger(const OsmMapPtr& map, WayMatchStringMappingPtr mapping,
    std::vector< std::pair<ElementId, ElementId> >& replaced);

  /**
   * Alternative constructor. If this is used operations that modify the map will fail.
   */
  WayMatchStringMerger(const ConstOsmMapPtr& map, WayMatchStringMappingPtr mapping);

  /**
   * Create a subline match string. This is useful if calling a highway classifier.
   */
  WaySublineMatchStringPtr createMatchString() const;

  QList<SublineMappingPtr> getAllSublineMappings() { return _sublineMappingOrder; }

  WayMatchStringMappingPtr getMapping() const { return _mapping; }

  /**
   * Merge scrapNode into the keeper way node at the end of a keeper way.
   */
  void mergeIntersection(ElementId scrapNodeId);

  /**
   * Merge scrapNode into the keeper way.
   */
  void mergeNode(ElementId scrapNode);

  /**
   * Merge all the tags from the scrap into the associated keeper ways.
   */
  void mergeTags();

  /**
   * Replaces all instances of the scrap elements with the associated set of keeper elements.
   */
  void replaceScraps();

  /**
   * Set the status on all the keeper ways.
   */
  void setKeeperStatus(Status s);

  void setTagMerger(ConstTagMergerPtr tagMerger) { _tagMerger = tagMerger; }

  /**
   * This must be called if any of the SublineMappingPtr values are changed. (e.g.
   * WayMatchStringSplitter)
   */
  void updateSublineMapping()
  { _rebuildWayString(WayNumber::Way1); _rebuildWayString(WayNumber::Way2); }

private:

  // white box testing
  friend class WayMatchStringMergerTest;

  OsmMapPtr _map;
  WayMatchStringMappingPtr _mapping;
  std::vector< std::pair<ElementId, ElementId> >& _replaced;
  QList<SublineMappingPtr> _sublineMappingOrder;
  QMap<ElementId, WayLocation> _nodeToWayLocation2;
  ConstTagMergerPtr _tagMerger;

  void _addSublineMapping(SublineMappingPtr sm);

  void _createWayMappings(WayLocation split1, WayLocation split2, WaySubline subline2);

  WayLocation _findNodeLocation2(WayStringPtr ws, ElementId nodeId);

  void _moveNode(ElementId scrapNodeId, WayLocation wl1);

  void _rebuildWayString(WayNumber way);

  /**
   * Using WayLocation::SLOPPY_EPSILON snap locations that are nearly at the end of a way to the
   * end of a way.
   */
  WayLocation _snapToEnd(const WayLocation& wl) const;

  void _splitPrimary();
};

typedef boost::shared_ptr<WayMatchStringMerger> WayMatchStringMergerPtr;
typedef boost::shared_ptr<const WayMatchStringMerger> ConstWayMatchStringMergerPtr;

}

#endif // WAYSTRINGMERGER_H
