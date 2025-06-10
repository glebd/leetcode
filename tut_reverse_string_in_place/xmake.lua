target("tut_reverse_string_in_place")
  set_kind("binary")
  add_files("main.cpp")
  add_links("gtest_main", "gtest")
