<?php

/**
 * Implementation of hook_user_default_roles().
 */
function blue_yourself_user_default_roles() {
  $roles = array();

  // Exported role: anonymous user
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
  );

  return $roles;
}
