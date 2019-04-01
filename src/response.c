#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

#include "../include/dqlite.h"

#include "./lib/assert.h"

#include "error.h"
#include "lifecycle.h"
#include "message.h"
#include "response.h"
#include "schema.h"

#define RESPONSE__IMPLEMENT(LOWER, UPPER, _) \
	SERIALIZE__IMPLEMENT(response_##LOWER, RESPONSE_##UPPER);

RESPONSE__TYPES(RESPONSE__IMPLEMENT, );

SCHEMA__IMPLEMENT(response_failure_, RESPONSE__SCHEMA_FAILURE);
SCHEMA__IMPLEMENT(response_server_, RESPONSE__SCHEMA_SERVER);
SCHEMA__IMPLEMENT(response_welcome_, RESPONSE__SCHEMA_WELCOME);
SCHEMA__IMPLEMENT(response_servers, RESPONSE__SCHEMA_SERVERS);
SCHEMA__IMPLEMENT(response_db_, RESPONSE__SCHEMA_DB);
SCHEMA__IMPLEMENT(response_stmt_, RESPONSE__SCHEMA_STMT);
SCHEMA__IMPLEMENT(response_result, RESPONSE__SCHEMA_RESULT);
SCHEMA__IMPLEMENT(response_rows, RESPONSE__SCHEMA_ROWS);
SCHEMA__IMPLEMENT(response_empty, RESPONSE__SCHEMA_EMPTY);

SCHEMA__HANDLER_IMPLEMENT(response, RESPONSE__SCHEMA_TYPES);
