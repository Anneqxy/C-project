add_test( [==[test_remove (0 child)]==] /workspaces/cs225/lab_bst/build/test [==[test_remove (0 child)]==]  )
set_tests_properties( [==[test_remove (0 child)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/lab_bst/build)
add_test( [==[test_remove (1 child)]==] /workspaces/cs225/lab_bst/build/test [==[test_remove (1 child)]==]  )
set_tests_properties( [==[test_remove (1 child)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/lab_bst/build)
add_test( [==[test_remove (2 child)]==] /workspaces/cs225/lab_bst/build/test [==[test_remove (2 child)]==]  )
set_tests_properties( [==[test_remove (2 child)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/lab_bst/build)
add_test( [==[test_allBuild 1]==] /workspaces/cs225/lab_bst/build/test [==[test_allBuild 1]==]  )
set_tests_properties( [==[test_allBuild 1]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/lab_bst/build)
add_test( [==[test_allBuild 2]==] /workspaces/cs225/lab_bst/build/test [==[test_allBuild 2]==]  )
set_tests_properties( [==[test_allBuild 2]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/lab_bst/build)
add_test( [==[test_allBuild 3]==] /workspaces/cs225/lab_bst/build/test [==[test_allBuild 3]==]  )
set_tests_properties( [==[test_allBuild 3]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/lab_bst/build)
set( test_TESTS [==[test_remove (0 child)]==] [==[test_remove (1 child)]==] [==[test_remove (2 child)]==] [==[test_allBuild 1]==] [==[test_allBuild 2]==] [==[test_allBuild 3]==])