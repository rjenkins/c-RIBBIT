lib_LTLIBRARIES = libribbit.la
libribbit_la_SOURCES = ribbit.c Croak.c ber_decoder.c constr_SEQUENCE_OF.c constr_SET_OF.c FrogTip.c constr_SEQUENCE.c INTEGER.c UTF8String.c asn_codecs_prim.c constraints.c OCTET_STRING.c ber_tlv_tag.c ber_tlv_length.c asn_SET_OF.c constr_TYPE.c per_decoder.c xer_decoder.c per_encoder.c xer_encoder.c per_support.c per_opentype.c xer_support.c der_encoder.c
libribbit_la_LDFLAGS = -lcurl

bin_PROGRAMS = croak 
croak_SOURCES = croak_exec.c
croak_CPPFLAGS = $(libdl_CFLAGS)
croak_LDFLAGS = -ldl 
