cc_test(
    name = "my_test",
    srcs = ["my_test.cc"],
    copts = ["-Iexternal/gtest/include",
             ],
    deps = ["@gtest//:main",
            "//chp_1:test",
            "//chp_3:test",
            "//chp_4:test",
            "//chp_5:test",
            "//chp_6:test",
            "//chp_7:test",
            "//chp_8:test",
            "//chp_11:test",
            "//chp_18:test",
            "//chp_19:test",
            "//chp_22:test",
            ],
    timeout = "short",
)