/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "RibbitProtocol"
 * 	found in "ribbit.asn1"
 */

#ifndef	_Croak_H_
#define	_Croak_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct FrogTip;

/* Croak */
typedef struct Croak {
	A_SEQUENCE_OF(struct FrogTip) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Croak_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Croak;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "FrogTip.h"

#endif	/* _Croak_H_ */
#include <asn_internal.h>