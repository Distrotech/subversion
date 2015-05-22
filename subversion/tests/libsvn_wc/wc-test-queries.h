/* This file is automatically generated from wc-test-queries.sql and .dist_sandbox/subversion-1.9.0-rc1/subversion/tests/libsvn_wc/token-map.h.
 * Do not edit this file -- edit the source and rerun gen-make.py */

#define STMT_SELECT_NODES_INFO 0
#define STMT_0_INFO {"STMT_SELECT_NODES_INFO", NULL}
#define STMT_0 \
  "SELECT op_depth, n.presence, n.local_relpath, revision, " \
  "       repos_path, file_external, def_local_relpath, moved_to, moved_here, " \
  "       properties " \
  "FROM nodes n " \
  "LEFT OUTER JOIN externals e " \
  "            ON n.wc_id = e.wc_id " \
  "                AND n.local_relpath = e.local_relpath " \
  "WHERE n.wc_id = ?1 " \
  "  AND (n.local_relpath = ?2 OR (((n.local_relpath) > (CASE (?2) WHEN '' THEN '' ELSE (?2) || '/' END)) AND ((n.local_relpath) < CASE (?2) WHEN '' THEN X'FFFF' ELSE (?2) || '0' END))) " \
  ""

#define STMT_SELECT_ACTUAL_INFO 1
#define STMT_1_INFO {"STMT_SELECT_ACTUAL_INFO", NULL}
#define STMT_1 \
  "SELECT local_relpath " \
  "FROM actual_node " \
  "WHERE wc_id = ?1 " \
  "  AND conflict_data is NOT NULL " \
  "  AND (local_relpath = ?2 OR (((local_relpath) > (CASE (?2) WHEN '' THEN '' ELSE (?2) || '/' END)) AND ((local_relpath) < CASE (?2) WHEN '' THEN X'FFFF' ELSE (?2) || '0' END))) " \
  ""

#define STMT_DELETE_NODES 2
#define STMT_2_INFO {"STMT_DELETE_NODES", NULL}
#define STMT_2 \
  "DELETE FROM nodes; " \
  ""

#define STMT_INSERT_NODE 3
#define STMT_3_INFO {"STMT_INSERT_NODE", NULL}
#define STMT_3 \
  "INSERT INTO nodes (local_relpath, op_depth, presence, repos_path, " \
  "                   revision, parent_relpath, moved_to, moved_here, " \
  "                   properties, wc_id, repos_id, kind, " \
  "                   depth) " \
  "           VALUES (?1, ?2, ?3, ?4, ?5, ?6, ?7, ?8, ?9, 1, " \
  "                   CASE WHEN ?3 != 'base-deleted' THEN 1 END, " \
  "                   'dir', " \
  "                   CASE WHEN ?3 in ('normal', 'incomplete') " \
  "                        THEN 'infinity' END) " \
  ""

#define STMT_DELETE_ACTUAL 4
#define STMT_4_INFO {"STMT_DELETE_ACTUAL", NULL}
#define STMT_4 \
  "DELETE FROM actual_node; " \
  ""

#define STMT_INSERT_ACTUAL 5
#define STMT_5_INFO {"STMT_INSERT_ACTUAL", NULL}
#define STMT_5 \
  "INSERT INTO actual_node (local_relpath, parent_relpath, changelist, wc_id) " \
  "                VALUES (?1, ?2, ?3, 1) " \
  ""

#define STMT_ENSURE_EMPTY_PRISTINE 6
#define STMT_6_INFO {"STMT_ENSURE_EMPTY_PRISTINE", NULL}
#define STMT_6 \
  "INSERT OR IGNORE INTO pristine (checksum, md5_checksum, size, refcount) " \
  "  VALUES ('$sha1$da39a3ee5e6b4b0d3255bfef95601890afd80709', " \
  "          '$md5 $d41d8cd98f00b204e9800998ecf8427e', " \
  "          0, 0) " \
  ""

#define STMT_NODES_SET_FILE 7
#define STMT_7_INFO {"STMT_NODES_SET_FILE", NULL}
#define STMT_7 \
  "UPDATE nodes " \
  "   SET kind = 'file', " \
  "       checksum = '$sha1$da39a3ee5e6b4b0d3255bfef95601890afd80709', " \
  "       depth = NULL " \
  "WHERE wc_id = 1 and local_relpath = ?1 " \
  ""

#define STMT_SELECT_ALL_ACTUAL 8
#define STMT_8_INFO {"STMT_SELECT_ALL_ACTUAL", NULL}
#define STMT_8 \
  "SELECT local_relpath FROM actual_node WHERE wc_id = 1 " \
  ""

#define WC_TEST_QUERIES_SQL_DECLARE_STATEMENTS(varname) \
  static const char * const varname[] = { \
    STMT_0, \
    STMT_1, \
    STMT_2, \
    STMT_3, \
    STMT_4, \
    STMT_5, \
    STMT_6, \
    STMT_7, \
    STMT_8, \
    NULL \
  }

#define WC_TEST_QUERIES_SQL_DECLARE_STATEMENT_INFO(varname) \
  static const char * const varname[][2] = { \
    STMT_0_INFO, \
    STMT_1_INFO, \
    STMT_2_INFO, \
    STMT_3_INFO, \
    STMT_4_INFO, \
    STMT_5_INFO, \
    STMT_6_INFO, \
    STMT_7_INFO, \
    STMT_8_INFO, \
    {NULL, NULL} \
  }
