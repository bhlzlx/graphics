.PHONY: clean All

All:
	@echo "----------Building project:[ scriptEngine - Debug ]----------"
	@cd "scriptEngine" && "$(MAKE)" -f  "scriptEngine.mk"
clean:
	@echo "----------Cleaning project:[ scriptEngine - Debug ]----------"
	@cd "scriptEngine" && "$(MAKE)" -f  "scriptEngine.mk" clean
