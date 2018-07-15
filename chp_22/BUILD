cc_library(
    name = "test",
    hdrs = [],
    srcs = glob(["*.cpp", "*.hpp"]),
    copts = ["-std=c++1z", "-Iexternal/gtest/include"],
    deps = ["@gtest//:main"],
    visibility = ["//visibility:public"]
)
