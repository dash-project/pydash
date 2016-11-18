#ifndef PYDASH__TEAM_H__INCLUDED
#define PYDASH__TEAM_H__INCLUDED

#include <libdash.h>
typedef int   bool;

CTeam         cdash__team__new(/**/);

CTeam         cdash__team__assign(CTeam _this, CTeam rhs);

void          cdash__team__delete(CTeam _this);

static CTeam  cdash__team__All();

static CTeam  cdash__team__Null();

static CTeam  cdash__team__Get();

static void   cdash__team__finalize();

void          cdash__team__register_deallocator(void * object,
                                                Deallocator::dealloc_function dealloc);

void          cdash__team__unregister_deallocator(void * object,
                                                  Deallocator::dealloc_function dealloc);

void          cdash__team__free();

CTeam &       cdash__team__split();

CTeam &       cdash__team__locality_split(dash::util::Locality::Scope scope,
                                          unsigned                    num_parts);

CTeam         cdash__team__equal(CTeam lhs, CTeam rhs);

CTeam         cdash__team__unequal(CTeam lhs, CTeam rhs);


bool          cdash__team__is_all() const;
bool          cdash__team__is_null() const;
bool          cdash__team__is_leaf() const;
bool          cdash__team__is_root() const;
bool          cdash__team__is_member(size_t groupId) const
dart_unit_t   cdash__team__myid() const;
size_t        cdash__team__size() const;
size_t        cdash__team__position() const;
dart_team_t   cdash__team__dart_id() const;
dart_unit_t   cdash__team__global_id(dart_unit_t local_id);

#endif /* PYDASH__TEAM_H__INCLUDED */
