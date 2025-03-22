house = "none"
repair_step = get_integer("General","RepairStep", 0 ,"rules+map")
if message_box("��Ҫ���޸����Ƶ��ƶ���������", "����������", 2) == 0 then
	box = select_box:new("ѡ��������")
	house_section = "Houses"
	load_from = "map"
	if is_multiplay() then
		house_section = "Countries"
		load_from = "rules+map"
	end
	for i,house in pairs(get_values(house_section, load_from)) do
		box:add_option(house, translate_house(house))
	end
	house = box:do_modal()
end

for i,building in pairs(get_buildings()) do
	if house ~= "none" and house ~= building.house then
		goto continue
	end
	if get_integer(building.type,"Strength", 0 ,"rules+map") < repair_step then
		building:remove()
		building.ai_repair = "0"
		building:place()
	end
	::continue::
end