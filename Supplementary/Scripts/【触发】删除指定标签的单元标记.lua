if message_box("���ű���ɾ��ѡ����ǩ�����е�Ԫ��ǣ�Ҫ������", "ɾ����Ԫ���", 2) == 0 then
	box = select_box:new("ѡ���ǩ")
	for i,k in pairs(get_keys("Tags")) do
		name = get_param("Tags", k, 2)
		box:add_option(k, name)
	end
	remove_celltags(box:do_modal())
end