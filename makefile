SUBDIR = chp_1
all:
	+$(MAKE) -C $(SUBDIR)
check:
	+$(MAKE) check -C $(SUBDIR)
