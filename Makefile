.PHONY: clean All

All:
	@echo "----------Building project:[ excel - Debug ]----------"
	@cd "excel" && "$(MAKE)" -f  "excel.mk"
clean:
	@echo "----------Cleaning project:[ excel - Debug ]----------"
	@cd "excel" && "$(MAKE)" -f  "excel.mk" clean
