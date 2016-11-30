#ifndef PYDASH__TEAM_H__INCLUDED
#define PYDASH__TEAM_H__INCLUDED

#include <libdash.h>


#ifdef __cplusplus
extern "C" {
#endif

typedef void * CTeam;
typedef void (*cdash__team__dealloc_fun_t(void));


CTeam         cdash__team__All();

CTeam         cdash__team__Null();

CTeam         cdash__team__Get();

void          cdash__team__finalize();

void          cdash__team__register_deallocator(
                void *                        object,
                cdash__team__dealloc_fun_t    dealloc);

void          cdash__team__unregister_deallocator(
                void *                        object,
                cdash__team__dealloc_fun_t    dealloc);

CTeam         cdash__team__split(
                CTeam _this,
                int   nparts);

CTeam         cdash__team__locality_split(

                dart_locality_scope_t         scope,
                unsigned                      num_parts);

bool          cdash__team__equal(
                CTeam lhs,
                CTeam rhs);

bool          cdash__team__is_all(CTeam _this);
bool          cdash__team__is_null(CTeam _this);
bool          cdash__team__is_leaf(CTeam _this);
bool          cdash__team__is_root(CTeam _this);
bool          cdash__team__is_member(CTeam _this, size_t groupId);
dart_unit_t   cdash__team__myid(CTeam _this);
size_t        cdash__team__size(CTeam _this);
size_t        cdash__team__position(CTeam _this);
void          cdash__team__barrier(CTeam _this);
dart_team_t   cdash__team__dart_id(CTeam _this);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* PYDASH__TEAM_H__INCLUDED */
