-- FLY HACK MOBILE - FULL MENU (1 SCRIPT DUY NHẤT)
local Player = game:GetService("Players").LocalPlayer
local Character = Player.Character or Player.CharacterAdded:Wait()
local Humanoid = Character:WaitForChild("Humanoid")
local RootPart = Character:WaitForChild("HumanoidRootPart")

-- CÀI ĐẶT
local isFlying = false
local flySpeed = 50
local originalGravity = workspace.Gravity
local bodyVelocity

-- TẠO GIAO DIỆN
local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name = "MobileFlyMenu"
ScreenGui.ResetOnSpawn = false

local MainFrame = Instance.new("Frame")
MainFrame.Size = UDim2.new(0, 350, 0, 400)
MainFrame.Position = UDim2.new(0.5, -175, 0.5, -200)
MainFrame.BackgroundColor3 = Color3.fromRGB(25, 25, 35)
MainFrame.BackgroundTransparency = 0.2
MainFrame.Active = true
MainFrame.Draggable = true

-- TIÊU ĐỀ
local Title = Instance.new("TextLabel")
Title.Text = "✈️ FLY HACK MOBILE"
Title.Size = UDim2.new(1, 0, 0, 50)
Title.BackgroundColor3 = Color3.fromRGB(40, 40, 60)
Title.TextColor3 = Color3.new(1, 1, 1)
Title.Font = Enum.Font.GothamBold
Title.TextSize = 18

-- TRẠNG THÁI
local Status = Instance.new("TextLabel")
Status.Text = "🛑 FLY: TẮT"
Status.Size = UDim2.new(1, 0, 0, 40)
Status.Position = UDim2.new(0, 0, 0, 60)
Status.TextColor3 = Color3.new(1, 0.5, 0.5)
Status.Font = Enum.Font.Gotham
Status.TextSize = 16

-- NÚT BẬT/TẮT
local ToggleBtn = Instance.new("TextButton")
ToggleBtn.Text = "🚀 BẬT FLY"
ToggleBtn.Size = UDim2.new(0.8, 0, 0, 60)
ToggleBtn.Position = UDim2.new(0.1, 0, 0, 110)
ToggleBtn.BackgroundColor3 = Color3.fromRGB(0, 150, 80)
ToggleBtn.TextColor3 = Color3.new(1, 1, 1)
ToggleBtn.Font = Enum.Font.GothamBold
ToggleBtn.TextSize = 20

-- TỐC ĐỘ
local SpeedFrame = Instance.new("Frame")
SpeedFrame.Size = UDim2.new(0.9, 0, 0, 100)
SpeedFrame.Position = UDim2.new(0.05, 0, 0, 190)
SpeedFrame.BackgroundColor3 = Color3.fromRGB(40, 40, 50)

local SpeedLabel = Instance.new("TextLabel")
SpeedLabel.Text = "TỐC ĐỘ: 50"
SpeedLabel.Size = UDim2.new(1, 0, 0, 30)
SpeedLabel.TextColor3 = Color3.new(1, 1, 1)
SpeedLabel.Font = Enum.Font.Gotham
SpeedLabel.TextSize = 16

local SpeedSlider = Instance.new("TextBox")
SpeedSlider.Text = "50"
SpeedSlider.PlaceholderText = "Nhập tốc độ..."
SpeedSlider.Size = UDim2.new(0.8, 0, 0, 40)
SpeedSlider.Position = UDim2.new(0.1, 0, 0, 40)
SpeedSlider.BackgroundColor3 = Color3.fromRGB(60, 60, 80)
SpeedSlider.TextColor3 = Color3.new(1, 1, 1)
SpeedSlider.Font = Enum.Font.Gotham

-- NÚT TĂNG/GIẢM TỐC ĐỘ
local SpeedUpBtn = Instance.new("TextButton")
SpeedUpBtn.Text = "➕ TĂNG"
SpeedUpBtn.Size = UDim2.new(0.4, 0, 0, 40)
SpeedUpBtn.Position = UDim2.new(0.05, 0, 0, 300)
SpeedUpBtn.BackgroundColor3 = Color3.fromRGB(60, 100, 200)

local SpeedDownBtn = Instance.new("TextButton")
SpeedDownBtn.Text = "➖ GIẢM"
SpeedDownBtn.Size = UDim2.new(0.4, 0, 0, 40)
SpeedDownBtn.Position = UDim2.new(0.55, 0, 0, 300)
SpeedDownBtn.BackgroundColor3 = Color3.fromRGB(200, 100, 60)

-- NÚT NO CLIP
local NoClipBtn = Instance.new("TextButton")
NoClipBtn.Text = "🔄 NO CLIP: TẮT"
NoClipBtn.Size = UDim2.new(0.8, 0, 0, 40)
NoClipBtn.Position = UDim2.new(0.1, 0, 0, 350)
NoClipBtn.BackgroundColor3 = Color3.fromRGB(80, 80, 100)

-- THÊM TẤT CẢ VÀO GUI
local elements = {Title, Status, ToggleBtn, SpeedLabel, SpeedSlider, SpeedUpBtn, SpeedDownBtn, NoClipBtn}
for _, element in pairs(elements) do
    element.Parent = MainFrame
    element.TextColor3 = Color3.new(1, 1, 1)
    element.Font = Enum.Font.Gotham
    if element:IsA("TextButton") then
        element.TextSize = 16
    end
end

SpeedLabel.Parent = SpeedFrame
SpeedSlider.Parent = SpeedFrame
SpeedFrame.Parent = MainFrame
MainFrame.Parent = ScreenGui
ScreenGui.Parent = Player:WaitForChild("PlayerGui")

-- CHỨC NĂNG FLY
local function startFlying()
    isFlying = true
    Status.Text = "✅ FLY: BẬT"
    Status.TextColor3 = Color3.new(0.5, 1, 0.5)
    ToggleBtn.Text = "✗ TẮT FLY"
    ToggleBtn.BackgroundColor3 = Color3.fromRGB(200, 60, 60)
    
    Humanoid:ChangeState(Enum.HumanoidStateType.Flying)
    workspace.Gravity = 0
    
    -- Tạo BodyVelocity cho điều khiển mượt
    if bodyVelocity then bodyVelocity:Destroy() end
    bodyVelocity = Instance.new("BodyVelocity")
    bodyVelocity.Velocity = Vector3.new(0, flySpeed, 0)
    bodyVelocity.MaxForce = Vector3.new(0, math.huge, 0)
    bodyVelocity.P = 10000
    bodyVelocity.Parent = RootPart
    
    print("🎯 Fly đã BẬT | Tốc độ: " .. flySpeed)
end

local function stopFlying()
    isFlying = false
    Status.Text = "🛑 FLY: TẮT"
    Status.TextColor3 = Color3.new(1, 0.5, 0.5)
    ToggleBtn.Text = "🚀 BẬT FLY"
    ToggleBtn.BackgroundColor3 = Color3.fromRGB(0, 150, 80)
    
    Humanoid:ChangeState(Enum.HumanoidStateType.Running)
    workspace.Gravity = originalGravity
    
    if bodyVelocity then
        bodyVelocity:Destroy()
        bodyVelocity = nil
    end
    
    print("✗ Fly đã TẮT")
end

-- CHỨC NĂNG THAY ĐỔI TỐC ĐỘ
local function updateSpeed()
    SpeedLabel.Text = "TỐC ĐỘ: " .. flySpeed
    SpeedSlider.Text = tostring(flySpeed)
    
    if isFlying and bodyVelocity then
        bodyVelocity.Velocity = Vector3.new(0, flySpeed, 0)
    end
end

-- NO CLIP FUNCTION
local noClip = false
local function toggleNoClip()
    noClip = not noClip
    NoClipBtn.Text = noClip and "✅ NO CLIP: BẬT" or "🔄 NO CLIP: TẮT"
    NoClipBtn.BackgroundColor3 = noClip and Color3.fromRGB(0, 150, 80) or Color3.fromRGB(80, 80, 100)
    
    for _, part in pairs(Character:GetDescendants()) do
        if part:IsA("BasePart") then
            part.CanCollide = not noClip
        end
    end
    
    print(noClip and "🔓 No Clip: BẬT" or "🔒 No Clip: TẮT")
end

-- KẾT NỐI SỰ KIỆN
ToggleBtn.MouseButton1Click:Connect(function()
    if isFlying then
        stopFlying()
    else
        startFlying()
    end
end)

SpeedUpBtn.MouseButton1Click:Connect(function()
    flySpeed = flySpeed + 10
    if flySpeed > 200 then flySpeed = 200 end
    updateSpeed()
end)

SpeedDownBtn.MouseButton1Click:Connect(function()
    flySpeed = flySpeed - 10
    if flySpeed < 10 then flySpeed = 10 end
    updateSpeed()
end)

SpeedSlider.FocusLost:Connect(function(enterPressed)
    if enterPressed then
        local newSpeed = tonumber(SpeedSlider.Text)
        if newSpeed and newSpeed >= 10 and newSpeed <= 200 then
            flySpeed = newSpeed
            updateSpeed()
        else
            SpeedSlider.Text = tostring(flySpeed)
        end
    end
end)

NoClipBtn.MouseButton1Click:Connect(toggleNoClip)

-- ĐIỀU KHIỂN BẰNG PHÍM ẢO
local UIS = game:GetService("UserInputService")
local virtualUp = Instance.new("TextButton")
virtualUp.Text = "⬆️"
virtualUp.Size = UDim2.new(0, 80, 0, 80)
virtualUp.Position = UDim2.new(1, -100, 1, -180)
virtualUp.BackgroundColor3 = Color3.fromRGB(60, 100, 200)
virtualUp.BackgroundTransparency = 0.3
virtualUp.Parent = ScreenGui

local virtualDown = Instance.new("TextButton")
virtualDown.Text = "⬇️"
virtualDown.Size = UDim2.new(0, 80, 0, 80)
virtualDown.Position = UDim2.new(1, -100, 1, -90)
virtualDown.BackgroundColor3 = Color3.fromRGB(200, 100, 60)
virtualDown.BackgroundTransparency = 0.3
virtualDown.Parent = ScreenGui

virtualUp.MouseButton1Down:Connect(function()
    if isFlying and bodyVelocity then
        bodyVelocity.Velocity = Vector3.new(0, flySpeed, 0)
    end
end)

virtualUp.MouseButton1Up:Connect(function()
    if isFlying and bodyVelocity then
        bodyVelocity.Velocity = Vector3.new(0, 0, 0)
    end
end)

virtualDown.MouseButton1Down:Connect(function()
    if isFlying and bodyVelocity then
        bodyVelocity.Velocity = Vector3.new(0, -flySpeed, 0)
    end
end)

virtualDown.MouseButton1Up:Connect(function()
    if isFlying and bodyVelocity then
        bodyVelocity.Velocity = Vector3.new(0, 0, 0)
    end
end)

-- AUTO RESET KHI CHẾT
Character:WaitForChild("Humanoid").Died:Connect(function()
    if isFlying then
        stopFlying()
    end
    if noClip then
        toggleNoClip()
    end
end)

-- THÔNG BÁO
print("====================================")
print("🚀 MOBILE FLY HACK ĐÃ SẴN SÀNG!")
print("📱 Menu hiển thị trên màn hình")
print("👉 Chạm nút để điều khiển")
print("⬆️⬇️ Nút ảo để bay lên/xuống")
print("====================================")

-- ẨN/HIỆN MENU BẰNG GESTURE
local lastTapTime = 0
UIS.TouchStarted:Connect(function(touch, gameProcessed)
    if not gameProcessed then
        local currentTime = tick()
        if currentTime - lastTapTime < 0.3 then
            -- Double tap to toggle menu
            MainFrame.Visible = not MainFrame.Visible
            virtualUp.Visible = MainFrame.Visible
            virtualDown.Visible = MainFrame.Visible
        end
        lastTapTime = currentTime
    end
end)