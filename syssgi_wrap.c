/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.13u-20020811-2332
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

/***********************************************************************
 * common.swg
 *
 *     This file contains generic SWIG runtime support for pointer
 *     type checking as well as a few commonly used macros to control
 *     external linkage.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 *
 * Copyright (c) 1999-2000, The University of Chicago
 * 
 * This file may be freely redistributed without license or fee provided
 * this copyright message remains intact.
 ************************************************************************/

#include <string.h>

#if defined(_WIN32) || defined(__WIN32__)
#       if defined(_MSC_VER)
#               if defined(STATIC_LINKED)
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) extern a
#               else
#                       define SWIGEXPORT(a) __declspec(dllexport) a
#                       define SWIGIMPORT(a) extern a
#               endif
#       else
#               if defined(__BORLANDC__)
#                       define SWIGEXPORT(a) a _export
#                       define SWIGIMPORT(a) a _export
#               else
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) a
#               endif
#       endif
#else
#       define SWIGEXPORT(a) a
#       define SWIGIMPORT(a) a
#endif

#ifdef SWIG_GLOBAL
#define SWIGRUNTIME(a) SWIGEXPORT(a)
#else
#define SWIGRUNTIME(a) static a
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

typedef struct swig_type_info {
  const char             *name;                 
  swig_converter_func     converter;
  const char             *str;
  swig_dycast_func        dcast;
  struct swig_type_info  *next;
  struct swig_type_info  *prev;
  void                   *clientdata;	
} swig_type_info;

#ifdef SWIG_NOINCLUDE

SWIGIMPORT(swig_type_info *) SWIG_TypeRegister(swig_type_info *);
SWIGIMPORT(swig_type_info *) SWIG_TypeCheck(char *c, swig_type_info *);
SWIGIMPORT(void *)           SWIG_TypeCast(swig_type_info *, void *);
SWIGIMPORT(swig_type_info *) SWIG_TypeDynamicCast(swig_type_info *, void **);
SWIGIMPORT(swig_type_info *) SWIG_TypeQuery(const char *);
SWIGIMPORT(void)             SWIG_TypeClientData(swig_type_info *, void *);

#else

static swig_type_info *swig_type_list = 0;

/* Register a type mapping with the type-checking */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeRegister(swig_type_info *ti)
{
  swig_type_info *tc, *head, *ret, *next;
  /* Check to see if this type has already been registered */
  tc = swig_type_list;
  while (tc) {
    if (strcmp(tc->name, ti->name) == 0) {
      /* Already exists in the table.  Just add additional types to the list */
      head = tc;
      next = tc->next;
      goto l1;
    }
    tc = tc->prev;
  }
  head = ti;
  next = 0;

  /* Place in list */
  ti->prev = swig_type_list;
  swig_type_list = ti;

  /* Build linked lists */
 l1:
  ret = head;
  tc = ti + 1;
  /* Patch up the rest of the links */
  while (tc->name) {
    head->next = tc;
    tc->prev = head;
    head = tc;
    tc++;
  }
  head->next = next;
  return ret;
}

/* Check the typename */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeCheck(char *c, swig_type_info *ty)
{
  swig_type_info *s;
  if (!ty) return 0;        /* Void pointer */
  s = ty->next;             /* First element always just a name */
  while (s) {
    if (strcmp(s->name,c) == 0) {
      if (s == ty->next) return s;
      /* Move s to the top of the linked list */
      s->prev->next = s->next;
      if (s->next) {
	s->next->prev = s->prev;
      }
      /* Insert s as second element in the list */
      s->next = ty->next;
      if (ty->next) ty->next->prev = s;
      ty->next = s;
      return s;
    }
    s = s->next;
  }
  return 0;
}

/* Cast a pointer up an inheritance hierarchy */
SWIGRUNTIME(void *) 
SWIG_TypeCast(swig_type_info *ty, void *ptr) 
{
  if ((!ty) || (!ty->converter)) return ptr;
  return (*ty->converter)(ptr);
}

/* Dynamic pointer casting. Down an inheritance hierarchy */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) 
{
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
     ty = (*ty->dcast)(ptr);
     if (ty) lastty = ty;
  }
  return lastty;
}

/* Search for a swig_type_info structure */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeQuery(const char *name) {
  swig_type_info *ty = swig_type_list;
  while (ty) {
    if (ty->str && (strcmp(name,ty->str) == 0)) return ty;
    if (ty->name && (strcmp(name,ty->name) == 0)) return ty;
    ty = ty->prev;
  }
  return 0;
}

/* Set the clientdata field for a type */
SWIGRUNTIME(void)
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_type_info *tc, *equiv;
  if (ti->clientdata) return;
  ti->clientdata = clientdata;
  equiv = ti->next;
  while (equiv) {
    if (!equiv->converter) {
      tc = swig_type_list;
      while (tc) {
	if ((strcmp(tc->name, equiv->name) == 0))
	  SWIG_TypeClientData(tc,clientdata);
	tc = tc->prev;
      }
    }
    equiv = equiv->next;
  }
}
#endif

#ifdef __cplusplus
}

#endif

/* -----------------------------------------------------------------------------
 * perl5.swg
 *
 * Perl5 runtime library
 * $Header: /cvs/projects/SWIG/Lib/perl5/Attic/perlrun.swg,v 1.1.2.7 2002/05/27 04:15:25 beazley Exp $
 * ----------------------------------------------------------------------------- */

#define SWIGPERL
#define SWIGPERL5
#ifdef __cplusplus
/* Needed on some windows machines---since MS plays funny
   games with the header files under C++ */
#include <math.h>
#include <stdlib.h>
extern "C" {
#endif
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* Get rid of free and malloc defined by perl */
#undef free
#undef malloc

#ifndef pTHX_
#define pTHX_
#endif

#include <string.h>
#ifdef __cplusplus
}
#endif

/* Note: SwigMagicFuncHack is a typedef used to get the C++
   compiler to just shut up already */

#ifdef PERL_OBJECT
#define MAGIC_PPERL  CPerlObj *pPerl = (CPerlObj *) this;
typedef int (CPerlObj::*SwigMagicFunc)(SV *, MAGIC *);

#ifdef __cplusplus
extern "C" {
#endif
typedef int (CPerlObj::*SwigMagicFuncHack)(SV *, MAGIC *);
#ifdef __cplusplus
}
#endif

#define SWIG_MAGIC(a,b) (SV *a, MAGIC *b)
#define SWIGCLASS_STATIC
#else
#define MAGIC_PPERL
#define SWIGCLASS_STATIC static
#ifndef MULTIPLICITY
#define SWIG_MAGIC(a,b) (SV *a, MAGIC *b)
typedef int (*SwigMagicFunc)(SV *, MAGIC *);

#ifdef __cplusplus
extern "C" {
#endif
typedef int (*SwigMagicFuncHack)(SV *, MAGIC *);
#ifdef __cplusplus
}
#endif


#else
#define SWIG_MAGIC(a,b) (struct interpreter *interp, SV *a, MAGIC *b)
typedef int (*SwigMagicFunc)(struct interpreter *, SV *, MAGIC *);
#ifdef __cplusplus
extern "C" {
#endif
typedef int (*SwigMagicFuncHack)(struct interpreter *, SV *, MAGIC *);
#ifdef __cplusplus
}
#endif

#endif
#endif

#if defined(WIN32) && defined(PERL_OBJECT) && !defined(PerlIO_exportFILE)
#define PerlIO_exportFILE(fh,fl) (FILE*)(fh)
#endif

/* Modifications for newer Perl 5.005 releases */

#if !defined(PERL_REVISION) || ((PERL_REVISION >= 5) && ((PERL_VERSION < 5) || ((PERL_VERSION == 5) && (PERL_SUBVERSION < 50))))
#ifndef PL_sv_yes
#define PL_sv_yes sv_yes
#endif
#ifndef PL_sv_undef
#define PL_sv_undef sv_undef
#endif
#ifndef PL_na
#define PL_na na
#endif
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SWIG_NOINCLUDE

#ifndef PERL_OBJECT
extern int SWIG_ConvertPtr(SV *, void **, swig_type_info *, int flags);
extern void SWIG_MakePtr(SV *, void *, swig_type_info *, int flags);
#else
extern int _SWIG_ConvertPtr(CPerlObj *, SV *, void **, swig_type_info *,int flags);
extern void _SWIG_MakePtr(CPerlObj *, SV *, void *, swig_type_info *, int flags);
#define SWIG_ConvertPtr(a,b,c,d) _SWIG_ConvertPtr(pPerl,a,b,c,d)
#define SWIG_MakePtr(a,b,c,d) _SWIG_MakePtr(pPerl,a,b,c,d)
#endif

#else

/* Function for getting a pointer value */

#ifndef PERL_OBJECT
SWIGRUNTIME(int) 
SWIG_ConvertPtr(SV *sv, void **ptr, swig_type_info *_t, int flags)
#else
#define SWIG_ConvertPtr(a,b,c,d) _SWIG_ConvertPtr(pPerl,a,b,c,d)
SWIGRUNTIME(int)
_SWIG_ConvertPtr(CPerlObj *pPerl, SV *sv, void **ptr, swig_type_info *_t, int flags)
#endif
{
  char *_c;
  swig_type_info *tc;
  IV   tmp;

  /* If magical, apply more magic */
  if (SvGMAGICAL(sv))
    mg_get(sv);

  /* Check to see if this is an object */
  if (sv_isobject(sv)) {
    SV *tsv = (SV*) SvRV(sv);
    if ((SvTYPE(tsv) == SVt_PVHV)) {
      MAGIC *mg;
      if (SvMAGICAL(tsv)) {
	mg = mg_find(tsv,'P');
	if (mg) {
	  SV *rsv = mg->mg_obj;
	  if (sv_isobject(rsv)) {
	    tmp = SvIV((SV*)SvRV(rsv));
	  }
	}
      } else {
	return -1;
      }
    } else {
      tmp = SvIV((SV*)SvRV(sv));
    }
    if (!_t) {
      *(ptr) = (void *) tmp;
      return 0;
    }
  } else if (! SvOK(sv)) {            /* Check for undef */
    *(ptr) = (void *) 0;
    return 0;
  } else if (SvTYPE(sv) == SVt_RV) {  /* Check for NULL pointer */
    *(ptr) = (void *) 0;
    if (!SvROK(sv)) 
      return 0;
    else
      return -1;
  } else {                            /* Don't know what it is */
      *(ptr) = (void *) 0;
      return -1;
  }
  if (_t) {
    /* Now see if the types match */      
    _c = HvNAME(SvSTASH(SvRV(sv)));
    tc = SWIG_TypeCheck(_c,_t);
    if (!tc) {
      *ptr = (void *) tmp;
      return -1;
    }
    *ptr = SWIG_TypeCast(tc,(void *)tmp);
    return 0;
  }
  *ptr = (void *) tmp;
  return 0;
}
#ifndef PERL_OBJECT
SWIGRUNTIME(void) 
SWIG_MakePtr(SV *sv, void *ptr, swig_type_info *t,int flags)
#else
#define SWIG_MakePtr(a,b,c,d) _SWIG_MakePtr(pPerl,a,b,c,d)
SWIGRUNTIME(void)
_SWIG_MakePtr(CPerlObj *pPerl, SV *sv, void *ptr, swig_type_info *t, int flags)
#endif
{
  sv_setref_pv(sv, (char *) t->name, ptr);
}

#endif

typedef XS(SwigPerlWrapper);
typedef SwigPerlWrapper *SwigPerlWrapperPtr;

/* Structure for command table */
typedef struct {
  const char         *name;
  SwigPerlWrapperPtr  wrapper;
} swig_command_info;

/* Information for constant table */

#define SWIG_INT     1
#define SWIG_FLOAT   2
#define SWIG_STRING  3
#define SWIG_POINTER 4
#define SWIG_BINARY  5

/* Constant information structure */
typedef struct swig_constant_info {
    int              type;
    const char      *name;
    long             lvalue;
    double           dvalue;
    void            *pvalue;
    swig_type_info **ptype;
} swig_constant_info;

#ifdef __cplusplus
}
#endif

/* Structure for variable table */
typedef struct {
  const char   *name;
  SwigMagicFunc   set;
  SwigMagicFunc   get;
  swig_type_info  **type;
} swig_variable_info;

/* Magic variable code */
#ifndef PERL_OBJECT
#define swig_create_magic(s,a,b,c) _swig_create_magic(s,a,b,c)
  #ifndef MULTIPLICITY 
       static void _swig_create_magic(SV *sv, char *name, int (*set)(SV *, MAGIC *), int \
(*get)(SV *,MAGIC *)) { 
  #else 
       static void _swig_create_magic(SV *sv, char *name, int (*set)(struct interpreter*,\
 SV *, MAGIC *), int (*get)(struct interpreter*, SV *,MAGIC *)) { 
  #endif 
#else
#define swig_create_magic(s,a,b,c) _swig_create_magic(pPerl,s,a,b,c)
static void _swig_create_magic(CPerlObj *pPerl, SV *sv, const char *name, int (CPerlObj::*set)(SV *, MAGIC *), int (CPerlObj::*get)(SV *, MAGIC *)) {
#endif
  MAGIC *mg;
  sv_magic(sv,sv,'U',(char *) name,strlen(name));
  mg = mg_find(sv,'U');
  mg->mg_virtual = (MGVTBL *) malloc(sizeof(MGVTBL));
  mg->mg_virtual->svt_get = (SwigMagicFuncHack) get;
  mg->mg_virtual->svt_set = (SwigMagicFuncHack) set;
  mg->mg_virtual->svt_len = 0;
  mg->mg_virtual->svt_clear = 0;
  mg->mg_virtual->svt_free = 0;
}







/* -------- TYPES TABLE (BEGIN) -------- */

static swig_type_info *swig_types[1];

/* -------- TYPES TABLE (END) -------- */

#define SWIG_init    boot_SGI__syssgi

#define SWIG_name   "SGI::syssgi::boot_SGI__syssgi"
#define SWIG_prefix "SGI::syssgi::"

#ifdef __cplusplus
extern "C"
#endif
#ifndef PERL_OBJECT
#ifndef MULTIPLICITY
SWIGEXPORT(void) SWIG_init (CV* cv);
#else
SWIGEXPORT(void) SWIG_init (pTHXo_ CV* cv);
#endif
#else
SWIGEXPORT(void) SWIG_init (CV *cv, CPerlObj *);
#endif

extern char *_SGI_SYSID(void);
extern char *_SGI_RDNAME(int,unsigned int);
extern char *_SGI_GETNVRAM(char *);
extern int _SGI_SETLED(int);
extern int _SGI_SETNVRAM(char *,char *);
extern int _SGI_SSYNC(void);
extern int _SGI_BDFLUSHCNT(unsigned int);
extern int _SGI_SET_AUTOPWRON(double);
extern int _SGI_GETTIMETRIM(void);
extern int _SGI_SETTIMETRIM(int);
#ifdef PERL_OBJECT
#define MAGIC_CLASS _wrap_syssgi_var::
class _wrap_syssgi_var : public CPerlObj {
public:
#else
#define MAGIC_CLASS
#endif
SWIGCLASS_STATIC int swig_magic_readonly(pTHX_ SV *sv, MAGIC *mg) {
    MAGIC_PPERL
    sv = sv; mg = mg;
    croak("Value is read-only.");
    return 0;
}


#ifdef PERL_OBJECT
};
#endif

#ifdef __cplusplus
extern "C" {
#endif
XS(_wrap__SGI_SYSID) {
    char *result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 0) || (items > 0)) {
        croak("Usage: _SGI_SYSID();");
    }
    result = (char *)_SGI_SYSID();
    
    ST(argvi) = sv_newmortal();
    sv_setpv((SV*)ST(argvi++), (char *) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_RDNAME) {
    int arg1 ;
    unsigned int arg2 ;
    char *result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 2) || (items > 2)) {
        croak("Usage: _SGI_RDNAME(process_id,buf_space);");
    }
    arg1 = (int) SvIV(ST(0));
    arg2 = (unsigned int) SvUV(ST(1));
    result = (char *)_SGI_RDNAME(arg1,arg2);
    
    ST(argvi) = sv_newmortal();
    sv_setpv((SV*)ST(argvi++), (char *) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_GETNVRAM) {
    char *arg1 ;
    char *result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 1) || (items > 1)) {
        croak("Usage: _SGI_GETNVRAM(prom_variable);");
    }
    if (!SvOK((SV*) ST(0))) arg1 = 0;
    else arg1 = (char *) SvPV(ST(0), PL_na);
    result = (char *)_SGI_GETNVRAM(arg1);
    
    ST(argvi) = sv_newmortal();
    sv_setpv((SV*)ST(argvi++), (char *) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_SETLED) {
    int arg1 ;
    int result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 1) || (items > 1)) {
        croak("Usage: _SGI_SETLED(led_state);");
    }
    arg1 = (int) SvIV(ST(0));
    result = (int)_SGI_SETLED(arg1);
    
    ST(argvi) = sv_newmortal();
    sv_setiv(ST(argvi++), (IV) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_SETNVRAM) {
    char *arg1 ;
    char *arg2 ;
    int result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 2) || (items > 2)) {
        croak("Usage: _SGI_SETNVRAM(prom_variable,prom_value);");
    }
    if (!SvOK((SV*) ST(0))) arg1 = 0;
    else arg1 = (char *) SvPV(ST(0), PL_na);
    if (!SvOK((SV*) ST(1))) arg2 = 0;
    else arg2 = (char *) SvPV(ST(1), PL_na);
    result = (int)_SGI_SETNVRAM(arg1,arg2);
    
    ST(argvi) = sv_newmortal();
    sv_setiv(ST(argvi++), (IV) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_SSYNC) {
    int result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 0) || (items > 0)) {
        croak("Usage: _SGI_SSYNC();");
    }
    result = (int)_SGI_SSYNC();
    
    ST(argvi) = sv_newmortal();
    sv_setiv(ST(argvi++), (IV) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_BDFLUSHCNT) {
    unsigned int arg1 ;
    int result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 1) || (items > 1)) {
        croak("Usage: _SGI_BDFLUSHCNT(kern_write_delay);");
    }
    arg1 = (unsigned int) SvUV(ST(0));
    result = (int)_SGI_BDFLUSHCNT(arg1);
    
    ST(argvi) = sv_newmortal();
    sv_setiv(ST(argvi++), (IV) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_SET_AUTOPWRON) {
    double arg1 ;
    int result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 1) || (items > 1)) {
        croak("Usage: _SGI_SET_AUTOPWRON(power_on);");
    }
    arg1 = (double) SvNV(ST(0));
    
    result = (int)_SGI_SET_AUTOPWRON(arg1);
    
    ST(argvi) = sv_newmortal();
    sv_setiv(ST(argvi++), (IV) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_GETTIMETRIM) {
    int result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 0) || (items > 0)) {
        croak("Usage: _SGI_GETTIMETRIM();");
    }
    result = (int)_SGI_GETTIMETRIM();
    
    ST(argvi) = sv_newmortal();
    sv_setiv(ST(argvi++), (IV) result);
    XSRETURN(argvi);
}


XS(_wrap__SGI_SETTIMETRIM) {
    int arg1 ;
    int result;
    int argvi = 0;
    dXSARGS;
    
    if ((items < 1) || (items > 1)) {
        croak("Usage: _SGI_SETTIMETRIM(timetrim_value);");
    }
    arg1 = (int) SvIV(ST(0));
    result = (int)_SGI_SETTIMETRIM(arg1);
    
    ST(argvi) = sv_newmortal();
    sv_setiv(ST(argvi++), (IV) result);
    XSRETURN(argvi);
}



/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */


static swig_type_info *swig_types_initial[] = {
0
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */

static swig_constant_info swig_constants[] = {
{ SWIG_STRING,  (char *) SWIG_prefix "VERSION", 0, 0, (void *)"0.1.1", 0},
{ SWIG_STRING,  (char *) SWIG_prefix "NVRAM_INITSTATE", 0, 0, (void *)"initstate", 0},
{ SWIG_STRING,  (char *) SWIG_prefix "NVRAM_PATH", 0, 0, (void *)"path", 0},
{ SWIG_STRING,  (char *) SWIG_prefix "NVRAM_SHOWCONFIG", 0, 0, (void *)"showconfig", 0},
{ SWIG_STRING,  (char *) SWIG_prefix "NVRAM_SWAP", 0, 0, (void *)"swap", 0},
{ SWIG_STRING,  (char *) SWIG_prefix "NVRAM_VERBOSE", 0, 0, (void *)"verbose", 0},
{0}
};
#ifdef __cplusplus
}
#endif
static swig_variable_info swig_variables[] = {
{0}
};
static swig_command_info swig_commands[] = {
{"SGI::syssgi::_SGI_SYSID", _wrap__SGI_SYSID},
{"SGI::syssgi::_SGI_RDNAME", _wrap__SGI_RDNAME},
{"SGI::syssgi::_SGI_GETNVRAM", _wrap__SGI_GETNVRAM},
{"SGI::syssgi::_SGI_SETLED", _wrap__SGI_SETLED},
{"SGI::syssgi::_SGI_SETNVRAM", _wrap__SGI_SETNVRAM},
{"SGI::syssgi::_SGI_SSYNC", _wrap__SGI_SSYNC},
{"SGI::syssgi::_SGI_BDFLUSHCNT", _wrap__SGI_BDFLUSHCNT},
{"SGI::syssgi::_SGI_SET_AUTOPWRON", _wrap__SGI_SET_AUTOPWRON},
{"SGI::syssgi::_SGI_GETTIMETRIM", _wrap__SGI_GETTIMETRIM},
{"SGI::syssgi::_SGI_SETTIMETRIM", _wrap__SGI_SETTIMETRIM},
{0,0}
};

#ifdef __cplusplus
extern "C"
#endif

XS(SWIG_init) {
    dXSARGS;
    int i;
    for (i = 0; swig_types_initial[i]; i++) {
        swig_types[i] = SWIG_TypeRegister(swig_types_initial[i]);
    }
    
    /* Install commands */
    for (i = 0; swig_commands[i].name; i++) {
        newXS((char*) swig_commands[i].name,swig_commands[i].wrapper, (char*)__FILE__);
    }
    
    /* Install variables */
    for (i = 0; swig_variables[i].name; i++) {
        SV *sv;
        sv = perl_get_sv((char*) swig_variables[i].name, TRUE | 0x2);
        if (swig_variables[i].type) {
            SWIG_MakePtr(sv,(void *)1, *swig_variables[i].type,0);
        }else {
            sv_setiv(sv,(IV) 0);
        }
        swig_create_magic(sv, (char *) swig_variables[i].name, swig_variables[i].set, swig_variables[i].get); 
    }
    
    /* Install constant */
    for (i = 0; swig_constants[i].type; i++) {
        SV *sv;
        sv = perl_get_sv((char*)swig_constants[i].name, TRUE | 0x2);
        switch(swig_constants[i].type) {
            case SWIG_INT:
            sv_setiv(sv, (IV) swig_constants[i].lvalue);
            break;
            case SWIG_FLOAT:
            sv_setnv(sv, (double) swig_constants[i].dvalue);
            break;
            case SWIG_STRING:
            sv_setpv(sv, (char *) swig_constants[i].pvalue);
            break;
            case SWIG_POINTER:
            SWIG_MakePtr(sv, swig_constants[i].pvalue, *(swig_constants[i].ptype),0);
            break;
            case SWIG_BINARY:
            /*      obj = SWIG_NewPackedObj(swig_constants[i].pvalue, swig_constants[i].lvalue, *(swig_constants[i].ptype)); */
            break;
            default:
            break;
        }
        SvREADONLY_on(sv);
    }
    
    ST(0) = &PL_sv_yes;
    XSRETURN(1);
}

