if is_multiplay() == false then
	if message_box("���ű���ɾ��ѡ�������������л��ؽڵ㣬Ҫ������", "ɾ�����ؽڵ�", 2) == 1 then
		box = select_box:new("ѡ��������")
		for i,house in pairs(get_values("Houses", "map")) do
			box:add_option(house, translate_house(house))
		end
		house = box:do_modal()
		for i=0,999 do
			key = string.format("%03d", i)
			delete_key(house, key)
		end
		write_string(house, "NodeCount", "0")
		update_node()
	end
end