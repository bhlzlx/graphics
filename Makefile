.PHONY: clean All

All:
	@echo "----------Building project:[ wx - Debug ]----------"
	@cd "wx" && $(MAKE) -f  "wx.mk"
clean:
	@echo "----------Cleaning project:[ wx - Debug ]----------"
	@cd "wx" && $(MAKE) -f  "wx.mk" clean
