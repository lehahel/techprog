//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

using boost::filesystem::current_path;
using boost::filesystem::create_directory;
using boost::filesystem::remove_all;

class TreeTestCase : public ::testing::Test {
public:
    void SetUp();
    void TearDown();
    std::string file_path; 
};


