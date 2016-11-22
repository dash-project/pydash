#include "cdash/src/Team.h"
#include "dash/Team.h"


CTeam cdash__team__new(/**/)
{
  return reinterpret_cast<CTeam>dash::Team(/* ... */);
}

CTeam cdash__team__assign(CTeam _this, CTeam rhs)
{
  _this = rhs;
}

void cdash__team__delete(CTeam _this)
{
  delete(_this);
}

static CTeam cdash__team__All(CTeam _this)
{
  return reinterpret_cast<CTeam>(_this.All());
}


static CTeam cdash__team__Null(CTeam _this)
{
  return reinterpret_cast<CTeam>(_this.Null());
}


static CTeam cdash__team__Get(CTeam _this)
{
  return reinterpret_cast<CTeam>(_this.Get());
}

static void cdash__team__finalize(CTeam _this)
{
  (_this.finalize());
}
/*
void cdash_team__register_deallocator(CTeam       _this,
                                      void *      object,
                                      Deallocator dealloc)
{
  //
}
*/

void dash__team__free(CTeam _this)
{
  (_this.free());
}

CTeam & cdash__team__split()
{
  (_this.split());
}

/*
CTeam &       cdash__team__locality_split(dash::util::Locality::Scope scope,
                                              unsigned                    num_parts);
*/

bool cdash__team__equal(CTeam lhs, CTeam rhs)
{
  (lhs == rhs);
}

bool cdash__team__unequal(CTeam lhs, CTeam rhs)
{
  (lhs != rhs);
}

bool cdash__team__is_all(CTeam _this) const
{
 return (_this.is_all());
}

bool cdash__team__is_null(CTeam _this) const
{
  return (_this.is_null());
}

bool          cdash__team__is_leaf(CTeam _this) const
{
  return (_this.is_leaf());
}

bool cdash__team__is_root(CTeam _this) const
{
  return (_this.is_root());
}

bool cdash__team__is_member(CTeam  _this,
                                     size_t groupId) const
{
  return (_this.is_member());
}

dart_unit_t cdash__team__myid(CTeam _this) const
{
  return (_this.is_leaf());
}

size_t cdash__team__size(CTeam _this) const
{
  return reinterpret_cast<size_t>(_this.size());
}

size_t cdash__team__position(CTeam _this) const
{
  return reinterpret_cast<size_t>(_this.position());
}

void cdash__team__barrier(CTeam _this)
{
  (_this.barrier());
}

dart_team_t cdash__team__dart_id(CTeam _this) const
{
  return reinterpret_cast<dart_team_t>(_this.dart_id);
}

dart_unit_t cdash__team__global_id(dart_unit_t local_id)
{
  return reinterpret_cast<dart_unit_t>(local_id.global_id());
