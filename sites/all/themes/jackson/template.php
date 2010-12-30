<?php

/**
 * Set count variables so column numbers can be dynamic.
 */
function jackson_preprocess_page (&$vars) {
  $vars['preface'] = count(array_filter(array($vars['preface_one'], $vars['preface_two'], $vars['preface_three'])));
  $vars['columns'] = count(array_filter(array($vars['left'], $vars['right'])));
  count(array_filter(array($vars['left'], $vars['right']))) == 2 ? $vars['two_sidebars'] = true : $vars['two_sidebars'] = false;
  $vars['bottom'] = count(array_filter(array($vars['bottom_one'], $vars['bottom_two'], $vars['bottom_three'], $vars['bottom_four'])));
  // Display user account links.
  $vars['user_links'] = _jackson_user_links();
  //dpm($vars);
}

/**
 * User/account related links.
 */
function _jackson_user_links() {
  // Add user-specific links
  global $user;
  $user_links = array();
  if (empty($user->uid)) {
    $user_links['login'] = array('title' => t('Login'), 'href' => 'user');
    // Do not display register link if registration is not allowed.
    if (variable_get('user_register', 1)) {
      $user_links['register'] = array('title' => t('Register'), 'href' => 'user/register');
    }
  }
  else {
    $user_links['account'] = array('title' => t('Hello @username', array('@username' => $user->name)), 'href' => 'user', 'html' => TRUE);
    $user_links['logout'] = array('title' => t('Logout'), 'href' => "logout");
  }
  return $user_links;
}
