//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <fstream>

void TreeTestCase::SetUp() {
    file_path = current_path().string() + "/new_file";
    create_directory(file_path);

    std::ofstream fout(file_path + "/test_file.txt");
    fout << "wjefnrdkfbgjkn";
    fout.close();
    create_directory(file_path + "/test_folder");
}

void TreeTestCase::TearDown() {
    remove_all(file_path);
}

TEST_F(TreeTestCase, test1) {
    ASSERT_THROW(GetTree(file_path + "/idontexist", true), std::invalid_argument);
    ASSERT_THROW(GetTree(file_path + "/test_file.txt", true), std::invalid_argument);
    ASSERT_NO_THROW(GetTree(file_path, false));
    ASSERT_NO_THROW(GetTree(file_path, true));
}

TEST_F(TreeTestCase, test2) {
    ASSERT_TRUE(GetTree(file_path, false) == GetTree(file_path, false));
}