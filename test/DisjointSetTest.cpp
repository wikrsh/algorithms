#include "gtest/gtest.h"
#include "DisjointSet.h"

namespace {
  TEST(DisjointSetTest, DefaultState) {
    DisjointSet ds(5);

    EXPECT_FALSE(ds.same(0, 1));
    EXPECT_TRUE(ds.same(0, 0));
  }

  TEST(DisjointSetTest, Unite) {
    DisjointSet ds(5);

    ds.unite(0, 1);
    EXPECT_TRUE(ds.same(0, 1));
    EXPECT_FALSE(ds.same(0, 3));

    ds.unite(1, 2);
    EXPECT_TRUE(ds.same(0, 2));
    EXPECT_TRUE(ds.same(1, 0));
    EXPECT_TRUE(ds.same(2, 1));
    EXPECT_FALSE(ds.same(0, 3));

    ds.unite(1, 4);
    EXPECT_TRUE(ds.same(0, 4));
    EXPECT_FALSE(ds.same(1, 3));
  }
}
