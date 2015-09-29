.PHONY: clean All

All:
	@echo "----------Building project:[ audio - Debug ]----------"
	@cd "audio" && $(MAKE) -f  "audio.mk"
clean:
	@echo "----------Cleaning project:[ audio - Debug ]----------"
	@cd "audio" && $(MAKE) -f  "audio.mk" clean
