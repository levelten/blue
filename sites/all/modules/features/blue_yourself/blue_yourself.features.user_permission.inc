<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function blue_yourself_user_default_permissions() {
  $permissions = array();

  // Exported permission: create picture content
  $permissions['create picture content'] = array(
    'name' => 'create picture content',
    'roles' => array(
      '0' => 'anonymous user',
    ),
  );

  return $permissions;
}
