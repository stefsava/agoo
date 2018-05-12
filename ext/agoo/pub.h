// Copyright (c) 2018, Peter Ohler, All rights reserved.

#ifndef __AGOO_PUB_H__
#define __AGOO_PUB_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

struct _Text;
struct _Upgraded;
struct _Subject;

typedef enum {
    PUB_SUB	= 'S',
    PUB_CLOSE	= 'C',
    PUB_UN	= 'U',
    PUB_MSG	= 'M',
    PUB_WRITE	= 'W',
} PubKind;

// Generated by extened handlers and placed on the pub_queue to be pulled off
// in the con_loop.
typedef struct _Pub {
    struct _Pub		*next;
    PubKind		kind;
    struct _Upgraded	*up;
    struct _Subject	*subject;
    struct _Text	*msg;
} *Pub;

extern Pub	pub_close(struct _Upgraded *up);
extern Pub	pub_subscribe(struct _Upgraded *up, const char *subject, int slen);
extern Pub	pub_unsubscribe(struct _Upgraded *up, const char *subject, int slen);
extern Pub	pub_publish(const char *subject, int slen, const char *message, size_t mlen);
extern Pub	pub_write(struct _Upgraded *up, const char *message, size_t mlen, bool bin);
extern void	pub_destroy(Pub pub);

#endif // __AGOO_PUB_H__
