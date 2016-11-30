#include <cdash/Team.h>
#include <dash/Team.h>


CTeam cdash__team__All()
{
  return reinterpret_cast<CTeam>(&dash::Team::All());
}

CTeam cdash__team__Null()
{
  return reinterpret_cast<CTeam>(&dash::Team::Null());
}

void cdash__team__finalize()
{
  dash::Team::finalize();
}

CTeam cdash__team__split(CTeam _this, int nparts)
{
  return &(reinterpret_cast<dash::Team *>(_this)->split(nparts));
}

bool cdash__team__equal(CTeam lhs, CTeam rhs)
{
  return *(reinterpret_cast<dash::Team *>(lhs)) ==
         *(reinterpret_cast<dash::Team *>(rhs));
}

bool cdash__team__is_all(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->is_all();
}

bool cdash__team__is_null(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->is_null();
}

bool dash__team__is_leaf(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->is_leaf();
}

bool cdash__team__is_root(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->is_root();
}

bool cdash__team__is_member(CTeam  _this,
                            size_t group_id)
{
  return reinterpret_cast<dash::Team *>(_this)->is_member(group_id);
}

dart_unit_t cdash__team__myid(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->myid();
}

size_t cdash__team__size(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->size();
}

size_t cdash__team__position(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->position();
}

void cdash__team__barrier(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->barrier();
}

dart_team_t cdash__team__dart_id(CTeam _this)
{
  return reinterpret_cast<dash::Team *>(_this)->dart_id();
}

