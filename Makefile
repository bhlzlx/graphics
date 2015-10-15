.PHONY: clean All

All:
	@echo "----------Building project:[ core - Release ]----------"
	@cd "core" && "$(MAKE)" -f  "core.mk"
clean:
	@echo "----------Cleaning project:[ core - Release ]----------"
	@cd "core" && "$(MAKE)" -f  "core.mk" clean
