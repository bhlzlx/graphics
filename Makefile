.PHONY: clean All

All:
	@echo "----------Building project:[ core - Debug ]----------"
	@cd "core" && "$(MAKE)" -f  "core.mk"
clean:
	@echo "----------Cleaning project:[ core - Debug ]----------"
	@cd "core" && "$(MAKE)" -f  "core.mk" clean
