.PHONY: clean All

All:
	@echo "----------Building project:[ graphics - Debug ]----------"
	$(MAKE) -C "graphics" -f "graphics.mk"
clean:
	@echo "----------Cleaning project:[ graphics - Debug ]----------"
	$(MAKE) -C "graphics" -f "graphics.mk" clean
